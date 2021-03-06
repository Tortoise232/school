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
public class Scanner{
    private ArrayList<String> pif = new ArrayList<>(); //program internal form
    private HashMap<String, Integer> variableSymbolTable = new HashMap<>();
    private HashMap<String, Integer> instructionCodes = new HashMap<>();
    private HashMap<String, Integer> constantSymbolTable = new HashMap<>();
    private BufferedReader fileReader;
    private Map<Character, Integer> symbolCharacters = new HashMap<>();

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

    public Scanner(String sourceFile, String instructionCodesFile){
        try {
            initInstructionCodesTable(instructionCodesFile);
            BufferedReader bufferedReader = fileReader = new BufferedReader(new FileReader(sourceFile)) ;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
//this is not needed now
/*    static public boolean checkStatementValidity(String[] line){

        //this is horrible but it should work god damn it
        if(line[1] != ""
                && line[2] == "="
                && line[3] != ""
                && line[line.length] == ";"
                && line.length == 4)
            return true;

        return false;
    }*/
//this is not needed now
/*    public AssignStatement parseAssignStatement(String[] line){
        //means we parse a variable assign statement
        if(!checkStatementValidity(line))
            return null;
        if(line[0] == "var" )
            variableSymbolTable.put(line[1], Integer.parseInt(line[3]));
        else
            if(!constantSymbolTable.containsKey(line[1]))
                constantSymbolTable.put(line[1], Integer.parseInt(line[3]));
        return null;
    }*/

    //mad to-do at lab lol
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

    public boolean checkVar(String var){
        if(var.length() == 0)
            return true;

        if (var.charAt(0) > '0' && var.charAt(0) < '9')
            return false;

        return true;
    }

    public void parseLine(String line){
       //not for lab 2 boyooo
        /* String[] splitLine =  line.split(" ");
        if(splitLine.length == 0)
            return;
        switch (splitLine[0]){
            case "const":
            case "var":
                parseAssignStatement(splitLine); break;

        }*/
        line = parseSymbolCharacters(line);
        String[] splitLine = line.split(" ");


        for(int i = 0; i < splitLine.length; i ++){
            String element = splitLine[i];
            if(element == "" || element.length() == 0)
                continue;
            if(instructionCodes.containsKey(element))
                pif.add("(" + instructionCodes.get(element)  + ",-)");

            else {
                //this is quite stupid because it means all elements will be parsed as variables but it's easy to change
                if (!variableSymbolTable.containsKey(element)) {
                    try {
                        if (Integer.parseInt(element) > 0)
                            break;
                    } catch (Exception e) {
                    }
                    if (element.length() > 8) {
                        System.out.println("ERROR IDENTIFIER NAME TOO LONG: " + element + " AT LINE " + i);
                        break;
                    }
                    if (checkVar(element)){
                        variableSymbolTable.put(element, variableSymbolTable.size());
                        pif.add("(" + element + "," + variableSymbolTable.size() + ")");
                    }
                    else
                        System.out.println("ERROR INVALID IDENTIFIER: " + element + " AT LINE " + i);
                }
                else
                    pif.add("(" + element + "," + variableSymbolTable.size() + ")");
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
