package com.company;


import java.sql.Time;
import java.sql.Timestamp;
import java.time.Duration;
import java.time.Instant;
import java.util.Random;
import java.util.Timer;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
    public static int LIMIT = 100;
    public static int MAXNR = 100;
    public static int[][] a = new int[LIMIT][LIMIT];
    public static int[][] b = new int[LIMIT][LIMIT];
    public static int[][] c = new int[LIMIT][LIMIT];

    public static void main(String[] args) {
        // write your code here

    }

    void threadingSum() {
            ExecutorService executor = Executors.newFixedThreadPool(LIMIT);

            for(int i = 0; i < LIMIT; i++){
                Runnable worker = new ThreadWorker(i,'+');
                executor.execute(worker);
            }
        }


        void sequentialSum() {
            for (int i = 0; i < LIMIT; i++)
                for (int j = 0; j < LIMIT; j++)
                    c[i][j] = a[i][j] + b[i][j];
        }

        void threadingProduct() {
            ExecutorService executor = Executors.newFixedThreadPool(LIMIT);

            for(int i = 0; i < LIMIT; i++){
                Runnable worker = new ThreadWorker(i,'*');
                executor.execute(worker);
            }
        }

/*        void threadingProductAsync() {
            for (int i = 0; i < LIMIT; i++) {
                std::async(producLine, i);
            }
        }

        void threadingSumAsync() {
            for (int i = 0; i < LIMIT; i++)
                std::async(sumLine, i);
        }*/

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

        void  go()
        {
            fillMatrices();
            Instant timeStamp = Instant.now();
            Duration timeDiff = Duration.between(Instant.now(), Instant.now());

            timeStamp = getStamp();
            threadingSum();
            System.out.println("Thread pool sum: " + timeDiff.between(timeStamp, Instant.now()).toMillis());

            timeStamp = getStamp();
            threadingProduct();
            System.out.println("Thread pool product: " + timeDiff.between(timeStamp, Instant.now()).toMillis());

            timeStamp = getStamp();
            sequentialSum();
            System.out.println("Sequential sum: " + timeDiff.between(timeStamp, Instant.now()).toMillis());


            timeStamp = getStamp();
            sequentialProduct();
            System.out.println("Sequential product: " + timeDiff.between(timeStamp, Instant.now()).toMillis());



        }


    }

