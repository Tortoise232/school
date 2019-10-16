package com.company;

import java.sql.Time;
import java.time.Duration;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.*;

/**
 * Created by Petean Mihai on 11/12/2017.
 */
public class Controller {
    public static int LIMIT = 2000;
    public static int MAXNR = 100;
    public static int NUMBER_OF_THREADS = 5;
    public static int[][] a = new int[LIMIT][LIMIT];
    public static int[][] b = new int[LIMIT][LIMIT];
    public static int[][] c = new int[LIMIT][LIMIT];
    public static int[][] d = new int[LIMIT][LIMIT];
    public static int[][] e = new int[LIMIT][LIMIT];
    public static boolean FIRST_MUL = true;
    public Controller(int limit, int maxnr, int numberOfThreads){
        this.LIMIT = limit;
        this.MAXNR = maxnr;
        this.NUMBER_OF_THREADS = numberOfThreads;
    }

    public Controller(){};


    void waitForTasks( List<FutureTask<?>> futures){
        boolean allDone;
        do{
            allDone = true;
            for(FutureTask<?> future: futures)
                if(!future.isDone())
                    allDone = false;

        } while(!allDone);
    }

    void threadingProductAsync() {
        List<FutureTask<?>> futures = new ArrayList<>();
        ExecutorService executor = Executors.newFixedThreadPool(NUMBER_OF_THREADS);
        for (int i = 0; i < LIMIT; i++) {
            final int row = i;
            FutureTask<Integer> future =
                    new FutureTask<Integer>(new Callable<Integer>() {
                        public Integer call() {
                            int sum = 0;
                            for (int column = 0; column < Controller.LIMIT; column++) {
                                sum = 0;
                                for (int i = 0; i < Controller.LIMIT; i++){
                                    if(FIRST_MUL) {
                                        sum += Controller.a[row][i] * Controller.b[i][column];
                                        Controller.d[row][column] = sum;
                                    }
                                    else {
                                        sum += Controller.d[row][i] * Controller.c[i][column];
                                        Controller.e[row][column] = sum;
                                    }
                                }
                            }
                            return sum;
                        }});
            futures.add(future);
            executor.execute(future);
        }
        waitForTasks(futures);

    }

    Instant getStamp() {
        return Instant.now();
    }


    void fillMatrices() {
        for (int i = 0; i < LIMIT; i++)
            for (int j = 0; j < LIMIT; j++) {
                Random rn = new Random();
                a[i][j] = rn.nextInt() % MAXNR;
                b[i][j] = rn.nextInt() % MAXNR;
                c[i][j] = rn.nextInt() % MAXNR;
            }
    }

    String computeThreadingProducts(String result){
        Instant timeStamp = Instant.now();
        Duration timeDiff = Duration.between(Instant.now(), Instant.now());
        threadingProductAsync();
        result += "\nProduct between first 2 matrices: " + timeDiff.between(timeStamp, Instant.now()).toMillis() + "ms ";
        FIRST_MUL = false;
        threadingProductAsync();
        result += "\nProduct between other 2 matrices: " + timeDiff.between(timeStamp, Instant.now()).toMillis() + "ms ";
        return result;

    }

    String  go() throws InterruptedException {
        String result = "\nMatrixSize: " + LIMIT + "; Thread limit: " + NUMBER_OF_THREADS + " ";
        fillMatrices();
        result = computeThreadingProducts(result);
        return result;
    }
}
