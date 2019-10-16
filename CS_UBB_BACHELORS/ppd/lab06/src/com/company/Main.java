package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class Main {
    public static double[] result;
    public static ExecutorService karatsubaExecutor;
    public static void main(String[] args) throws InterruptedException {
        double[] a = {1,2,3,4};
        double[] b = {4,5,1};
        double[] simpleRes = multiplyPolynomialsSequentialSimple(a, b);
        System.out.println(simpleRes);
        double[] karatsubaRes = multiplyPolynomialsSequentialKaratsuba(a, b);
        System.out.println(simpleRes);
        double[] simpleThreadingRes = multiplyPolynomialsSequentialThreading(a, b);
        System.out.println(result);
        double[] threadingKaratsuba = multiplyPolynomialsThreadingKaratsuba(a, b);
        System.out.println(result);
        // write your code here
    }

    public static double[] fillPolynomial(int coeff, double[] b){
        double[] result = new double[coeff];
        for(int i = 0; i < coeff; i ++)
            if(b.length <= i )
                result[i] = 0;
            else
                result[i] = b[i];
        return result;
    }



    public static double[] multiplyPolynomialsSequentialSimple(double[] a, double[] b) {
        if(a.length > b.length)
            b = fillPolynomial(a.length, b);
        if(b.length > a.length)
            a = fillPolynomial(b.length, a);
        double[] result = new double[a.length + b.length];
        for (int ct_a = 0; ct_a < a.length; ct_a++) {
            for (int ct_b = 0; ct_b < b.length; ct_b++) {
                    result[ct_a + ct_b] += a[ct_a] * b[ct_b];
            }

        }
        return result;
    }

    public static double[] multiplyPolynomialsSequentialThreading(double[] a, double[] b) throws InterruptedException {
        if(a.length > b.length)
            b = fillPolynomial(a.length, b);
        if(b.length > a.length)
            a = fillPolynomial(b.length, a);
        double[] result = new double[a.length + b.length];
        ExecutorService executor =  Executors.newFixedThreadPool(10);
        for (int ct_a = 0; ct_a < a.length; ct_a++) {
            Runnable task =  new SimpleMultiplicationWorker(ct_a, a, b);
            executor.execute(task);
        }
        executor.shutdown();
        executor.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
        return result;
    }
    public static double[] multiplyPolynomialsSequentialKaratsuba(double[] a, double[] b){
        //normalise polynomials
        if(a.length > b.length)
            b = fillPolynomial(a.length, b);
        if(b.length > a.length)
            a = fillPolynomial(b.length, a);

        double[] result = karatsuba(a, b);
        return result;
    }

    public static double[] multiplyPolynomialsThreadingKaratsuba(double[] a, double[] b) throws InterruptedException {
        if(a.length > b.length)
            b = fillPolynomial(a.length, b);
        if(b.length > a.length)
            a = fillPolynomial(b.length, a);

        karatsubaExecutor = Executors.newFixedThreadPool(10);
        Runnable karatRun = new KaratsubaWorker(a, b, 0);
        karatsubaExecutor.execute(karatRun);
        karatsubaExecutor.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
        return result;
    }


    public static double[] karatsuba(double[] a, double[] b){
        double[] result = new double[a.length + b.length];
        if(a.length == 1){
            result = new double[1];
            result[0] = a[0] * b[0];
            System.out.println(result[0]);
            return result;
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
            result[i] = resultFirstHalf[i] + resultFirstHalfRev[i];
            result[i + half] = resultSecondHalf[i] + resultSecondHalfRev[i];
        }
        return result;
    }
}
