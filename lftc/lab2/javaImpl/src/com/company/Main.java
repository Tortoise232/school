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
        Scanner myScanner = new Scanner(fileName, "instructionCodes.txt");
        try {
            myScanner.readFile();
            System.out.println("Program Internal Form: " + myScanner.getPif());
            System.out.println("Instruction Codes (SymTable): " + myScanner.getInstructionCodes());
            System.out.println("Variables: " + myScanner.getVariableSymbolTable());

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
