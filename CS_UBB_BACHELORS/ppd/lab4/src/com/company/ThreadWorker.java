package com.company;

import java.util.concurrent.Callable;

/**
 * Created by Petean Mihai on 11/6/2017.
 */
public class ThreadWorker implements Runnable {
    private int line;
    private boolean doProduct = false;
    public ThreadWorker(int line){
        this.line = line;
    }
    @Override
    public void run() {
        producLine(line);
     }

    static void producLine(int row) {
        int sum;
        for (int column = 0; column < Controller.LIMIT; column++) {
            sum = 0;
            for (int i = 0; i < Controller.LIMIT; i++){
                sum += Controller.a[row][i] * Controller.b[i][column];
                Controller.d[row][column] = sum;
            }
        }
    }
}
