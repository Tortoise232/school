package com.company;

import static com.company.Main.result;

/**
 * Created by Petean Mihai on 12/3/2017.
 */
public class SimpleMultiplicationWorker implements Runnable {
    private double[] a;
    private double[] b;
    private int pos;
    public SimpleMultiplicationWorker(int pos, double[] a, double[] b){
        this.a = a;
        this.b = b;
        this.pos = pos;
    }


    @Override
    public void run(){
        double[] result = new double[a.length + b.length];

        //do the math
        for(int ct = 0; ct < b.length; ct ++){
            result[ct + pos] += a[pos] * b[ct];
        }

        //add back to result
        try {
            synchronized (Main.result) {
                for (int i = 0; i < result.length; i++) {
                    Main.result[i] += result[i];
                }
            }
        } catch(Exception e){
            e.printStackTrace();
        }
    }
}
