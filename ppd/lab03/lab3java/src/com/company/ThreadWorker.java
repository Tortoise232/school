package com.company;

/**
 * Created by Petean Mihai on 11/6/2017.
 */
public class ThreadWorker implements Runnable {
    private int line;
    private boolean doProduct = false;
    public ThreadWorker(int line, char purpose){
        this.line = line;
        if(purpose == '*')
            doProduct = true;
    }
    @Override
    public void run() {
        if(doProduct)
            producLine(line);
        else
            sumLine(line);
    }

    void producLine(int row) {
        int sum;
        for (int column = 0; column < Main.LIMIT; column++) {
            sum = 0;
            for (int i = 0; i < Main.LIMIT; i++){
                sum += Main.a[row][i] * Main.b[i][column];
                Main.c[row][column] = sum;
            }
        }
    }

    void sumLine(int line) {
        for (int i = 0; i < Main.LIMIT; i++) {
            Main.c[line][i] = Main.a[line][i] + Main.b[line][i];
        }
    }


}
