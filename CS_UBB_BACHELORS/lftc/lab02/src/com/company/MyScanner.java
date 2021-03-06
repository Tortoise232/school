package com.company;

import jdk.internal.util.xml.impl.Pair;

import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by Petean Mihai on 11/8/2017.
 */
public class MyScanner {
    private ArrayList<String> pif = new ArrayList<>(); //program internal form
    private HashMap<String, Integer> variableSymbolTable = new HashMap<>();
    private HashMap<String, Integer> instructionCodes = new HashMap<>();
    private HashMap<String, Integer> constantSymbolTable = new HashMap<>();
    private BufferedReader fileReader;
    private Map<Character, Integer> symbolCharacters = new HashMap<>();

    private FiniteAutomaton identifierAutomaton = new FiniteAutomaton("identifier.auto");
    private FiniteAutomaton integerAutomaton = new FiniteAutomaton("integer.auto");
    public MyScanner(File file) throws FileNotFoundException {
    }

    public ArrayList<String> getPif() {
        return pif;
    }
    private static int variableTableCounter = 0;

    public void setPif(ArrayList<String> pif) {
        this.pif = pif;
    }

    public HashMap<String, Integer> getVariableSymbolTable() {
        return variableSymbolTable;
    }

    public void setVariableSymbolTable(HashMap<String, Integer> variableSymbolTable) {
        this.variableSymbolTable = variableSymbolTable;
    }

    public HashMap<String, Integer> getInstructionCodes() {
        return instructionCodes;
    }

    public void setInstructionCodes(HashMap<String, Integer> instructionCodes) {
        this.instructionCodes = instructionCodes;
    }

    public HashMap<String, Integer> getConstantSymbolTable() {
        return constantSymbolTable;
    }

    public void setConstantSymbolTable(HashMap<String, Integer> constantSymbolTable) {
        this.constantSymbolTable = constantSymbolTable;
    }

    public BufferedReader getFileReader() {
        return fileReader;
    }

    public void setFileReader(BufferedReader fileReader) {
        this.fileReader = fileReader;
    }

    public boolean initInstructionCodesTable(String fileName) throws IOException {
        BufferedReader bufferedReader = fileReader = new BufferedReader(new FileReader(fileName)) ;
        String element = null;
        do{
            element = fileReader.readLine();
            instructionCodes.put(element, instructionCodes.size());
        }while(element != null);
        if(instructionCodes.size() > 0)
            return true;
        return false;
    }

    public MyScanner(String sourceFile, String instructionCodesFile) throws FileNotFoundException {
        try {
            initInstructionCodesTable(instructionCodesFile);
            BufferedReader bufferedReader = fileReader = new BufferedReader(new FileReader(sourceFile)) ;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public String parseSymbolCharacters(String line){
        //if a symbol inside the instruction code sym table has only one character, add it to the array
        for(String instructionCode : instructionCodes.keySet()){
            if(instructionCode == null)
                continue;
            if(instructionCode.length() == 1)
                symbolCharacters.put(instructionCode.charAt(0), instructionCodes.get(instructionCode));
        }
            for (Character charr : symbolCharacters.keySet())
                line = line.replace("" + charr, " " + charr + " ");
        return line;
    }

    public boolean allSpaces(String string){
        for(int ct = 0; ct < string.length(); ct ++)
            if(string.charAt(ct) != ' ')
                return false;
        return true;
    }

    //I AM PROUD OF THIS
    public String[] parseMissingSpaces(String[] line){
        int length = 0;
        String[] result = new String[100];
        for(String section: line) {
            if(section == null || allSpaces(section))
                continue;
            if (section.contains(",") && section.length() > 1) {
                section.replace(",", " , ");
                for (String subSection : section.split(" "))
                    result[length++] = subSection;
            } else
                result[length++] = section;
        }
        return line;
    }

    public void parseLine(String line){
        line = parseSymbolCharacters(line);
        String[] splitLine = line.split(" ");


        for(int i = 0; i < splitLine.length; i ++){
            String element = splitLine[i];
            if(element == "" || element.length() == 0)
                continue;
            if(integerAutomaton.checkSequence(element))
                pif.add("(" + element  + ", int)");
            else
                if(instructionCodes.containsKey(element))
                    pif.add("(" + instructionCodes.get(element)  + ", -)");
                else
                    if(identifierAutomaton.checkSequence(element)) {
                        variableSymbolTable.put(element, variableSymbolTable.size());
                        pif.add("(" + element + ", " + variableSymbolTable.size() + ")");
                    }

        }
    }

    public void readFile() throws IOException {
        String newStatement = fileReader.readLine();
        do{
            if(newStatement!= null)
                parseLine(newStatement);
            newStatement = fileReader.readLine();

        }while(newStatement != null);
    }

    public int executeProgram(ArrayList<IStatement> pif, HashMap<String, Integer> variableSymbolTable,  HashMap<String, Integer> constantSymbolTable){
        return 0;
    }
}
