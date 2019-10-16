package com.company;

/**
 * Created by Petean Mihai on 11/8/2017.
 */
public class AssignStatement implements IStatement {
    private Variable variable;
    private int value;
    public String toString(){return "" + variable + " = " + value;}
}
