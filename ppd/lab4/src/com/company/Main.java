package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Controller mc = new Controller();
        int nrThreads;
        try {
            for(int i = 0; i < 10; i ++)
                for(int j = 100; j < 1001; j += 100){
                    mc = new Controller(j, 100, i + 1);
                    System.out.print(mc.go());
                }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
