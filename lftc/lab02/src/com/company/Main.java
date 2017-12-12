package com.company;


import java.io.IOException;

// read x; citeste valoare in x;
public class Main {

    public static void main(String[] args) {
	// write your code here
        //parseFile("sourceFile.phal");
        parseFile("sourceFile.phal");
    }

    public static void parseFile(String fileName){
        MyScanner myMyScanner = new MyScanner(fileName, "instructionCodes.txt");
        try {
            myMyScanner.readFile();
            System.out.println("Program Internal Form: " + myMyScanner.getPif());
            System.out.println("Instruction Codes (SymTable): " + myMyScanner.getInstructionCodes());
            System.out.println("Variables: " + myMyScanner.getVariableSymbolTable());

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
