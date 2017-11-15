package com.company;


import java.io.IOException;

// read x; citeste valoare in x;
public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner myScanner = new Scanner("sourceFile.phal", "instructionCodes.txt");
        try {
            myScanner.readFile();
            System.out.println(myScanner.getPif());
            System.out.println(myScanner.getInstructionCodes());
            System.out.println(myScanner.getVariableSymbolTable());

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
