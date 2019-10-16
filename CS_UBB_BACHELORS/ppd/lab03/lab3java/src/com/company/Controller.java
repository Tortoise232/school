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
    public static int LIMIT = 1000;
    public static int MAXNR = 100;
    public static int NUMBER_OF_THREADS = 5;
    public static int[][] a = new int[LIMIT][LIMIT];
    public static int[][] b = new int[LIMIT][LIMIT];
    public static int[][] c = new int[LIMIT][LIMIT];

    public Controller(int limit, int maxnr, int numberOfThreads){
        this.LIMIT = limit;
        this.MAXNR = maxnr;
        this.NUMBER_OF_THREADS = numberOfThreads;
    }

    public Controller(){};

    void threadingSum() throws InterruptedException {
        ExecutorService executor = Executors.newFixedThreadPool(NUMBER_OF_THREADS);

        for(int i = 0; i < LIMIT; i++){
            Runnable worker = new ThreadWorker(i,'+');
            executor.execute(worker);
        }
        executor.shutdown();
        executor.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
    }


    void sequentialSum() {
        for (int i = 0; i < LIMIT; i++)
            for (int j = 0; j < LIMIT; j++)
                c[i][j] = a[i][j] + b[i][j];
    }

    void threadingProduct() throws InterruptedException {
        ExecutorService executor = Executors.newFixedThreadPool(NUMBER_OF_THREADS);

        for(int i = 0; i < LIMIT; i++){
            Runnable worker = new ThreadWorker(i,'*');
            executor.execute(worker);

        }
        executor.shutdown();
        executor.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);

    }

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
                                    sum += Controller.a[row][i] * Controller.b[i][column];
                                    Controller.c[row][column] = sum;
                                }
                            }
                            return sum;
                        }});
            futures.add(future);
            executor.execute(future);
        }
        waitForTasks(futures);
    }

    void threadingSumAsync() {
        List<FutureTask<?>> futures = new ArrayList<>();
        ExecutorService executor = Executors.newFixedThreadPool(NUMBER_OF_THREADS);
        for (int i = 0; i < LIMIT; i++) {
            final int row = i;
            FutureTask<Integer> future =
                    new FutureTask<Integer>(new Callable<Integer>() {
                        public Integer call() {
                            for (int i = 0; i < Controller.LIMIT; i++) {
                                Controller.c[row][i] = Controller.a[row][i] + Controller.b[row][i];
                            }
                            return 1;
                        }});
            futures.add(future);
            executor.execute(future);
        }
        waitForTasks(futures);
    }

    void sequentialProduct() {
        for (int i = 0; i < LIMIT; i++)
            for (int j = 0; j < LIMIT; j++) {
                int sum = 0;
                for (int ii = 0; ii < LIMIT; ii++)
                    sum += a[i][ii] * b[ii][j];
                c[i][j] = sum;
            }
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
            }
    }

    String  go() throws InterruptedException {
        String result = "MatrixSize: " + LIMIT + " ";
        fillMatrices();
        Instant timeStamp = Instant.now();
        Duration timeDiff = Duration.between(Instant.now(), Instant.now());


        timeStamp = getStamp();
        sequentialSum();
        result += "Sequential sum: " + timeDiff.between(timeStamp, Instant.now()).toMillis() + " ";

        timeStamp = getStamp();
        threadingSum();
        result += "Thread pool sum: " + timeDiff.between(timeStamp, Instant.now()).toMillis() + " ";
        timeStamp = getStamp();
        threadingSumAsync();
        result += "Async sum: " + timeDiff.between(timeStamp, Instant.now()).toMillis() + " ";
        timeStamp = getStamp();
        sequentialProduct();
        result += "Sequential product: " + timeDiff.between(timeStamp, Instant.now()).toMillis() + " ";
        timeStamp = getStamp();
        threadingProduct();
        result += "Thread pool product: " + timeDiff.between(timeStamp, Instant.now()).toMillis()+ " ";
        timeStamp = getStamp();
        threadingProductAsync();
        result += "Async product: " + timeDiff.between(timeStamp, Instant.now()).toMillis() + " ";

        return result;
    }
}
