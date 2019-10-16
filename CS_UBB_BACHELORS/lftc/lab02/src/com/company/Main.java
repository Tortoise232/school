package com.company;


import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

// read x; citeste valoare in x;
public class Main {
    //was java made in hell?
    private static String getInput() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    public static void main(String[] args) {
	// write your code here
        //parseFile("sourceFile.phal");
        System.out.println("1 read a finite automata from file and print state\n2 check a sequence(integer) \n3 run program parser (has some fa in it)");
        String input = getInput();


        if(input.contains("1")) {
            System.out.println("Source file for fa:");
            try {
                String filename = getInput();
                loadFA(filename);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
        if(input.contains("2")) {
            System.out.println("Integer sequence ples:");
            try {
                String seq = getInput();
                if(checkSequence(seq))
                    System.out.println("GREAT SACSES THE SEQUENCE " + seq + " IS A VALID SEQUENCE");
                else
                    System.out.println("NO GREAT SACSES THE SEQUENCE " + seq + " IS PRETTY BAD");
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
        if(input.contains("3")) {
            try {
                parseFile("circumference.phal");
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

    }

    public static void loadFA(String faFileName) throws FileNotFoundException {
        FiniteAutomaton myFa = new FiniteAutomaton(faFileName);
        System.out.println("GREAT SACSES: " + myFa.toString());
    }

    public static boolean checkSequence(String sequence) throws FileNotFoundException {
        FiniteAutomaton myFa = new FiniteAutomaton("integer.auto");
        return myFa.checkSequence(sequence);
    }

    public static void parseFile(String fileName) throws FileNotFoundException {
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
