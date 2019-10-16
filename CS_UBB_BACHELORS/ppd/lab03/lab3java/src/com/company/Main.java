package com.company;

public class Main {
    public static void main(String[] args) {
        // write your code here

        for(int matrixSize = 100; matrixSize < 1000; matrixSize += 100){
            Controller myController = new Controller(matrixSize, 100, 5);
            try {
                System.out.println(myController.go());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        }

    }
}

