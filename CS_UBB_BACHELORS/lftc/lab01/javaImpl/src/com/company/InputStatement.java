package com.company;

/**
 * Created by Petean Mihai on 11/8/2017.
 */
public class InputStatement implements IStatement{
    public Variable var;
    public String toString(){return "readInto: " +  var;}
}
