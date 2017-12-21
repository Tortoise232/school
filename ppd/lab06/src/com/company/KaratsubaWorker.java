package com.company;

import static com.company.Main.karatsuba;

/**
 * Created by Petean Mihai on 12/11/2017.
 */
public class KaratsubaWorker implements Runnable{
    private double[] a;
    private double[] b;
    private int position;

    public KaratsubaWorker(double[] a, double [] b, int position){
        this.a = a;
        this.b = b;
        this.position = position;
    }

    @Override
    public  void run(){
        if(a.length == 1){
            }
        int half = a.length / 2;
        double[] aFirstHalf = new double[half],
                bFirstHalf = new double[half],
                aSecondHalf = new double[half],
                bSecondHalf = new double[half];

        for(int ct = 0; ct <  half; ct ++)
        {
            aFirstHalf[ct] = a[ct];
            bFirstHalf[ct] = b[ct];
            aSecondHalf[ct] = a[ct + half];
            bSecondHalf[ct] = b[ct + half];
        }

        double[] resultFirstHalf;
        double[] resultSecondHalf;
        double[] resultFirstHalfRev;
        double[] resultSecondHalfRev;


        resultFirstHalf = karatsuba(aFirstHalf, bFirstHalf);
        resultSecondHalf = karatsuba(aSecondHalf, bSecondHalf);
        resultFirstHalfRev =  karatsuba(aFirstHalf, bSecondHalf);
        resultSecondHalfRev = karatsuba(aSecondHalf, bFirstHalf);


        for(int i = 0; i < half; i++){
            Main.result[i + position] = resultFirstHalf[i] + resultFirstHalfRev[i];
            Main.result[i + half + position] = resultSecondHalf[i] + resultSecondHalfRev[i];
        }
    }}
