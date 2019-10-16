package com.company;

import java.util.HashMap;

/**
 * Created by Petean Mihai on 11/8/2017.
 */
public class SymbolTable {
    private HashMap<Integer, Integer> map;

    public SymbolTable() {
        map = new HashMap<>();
    }

    public SymbolTable(HashMap<Integer, Integer> map) {

        this.map = map;
    }

    @Override
    public String toString() {
        return "SymbolTable{" +
                "map=" + map +
                '}';
    }

    public HashMap<Integer, Integer> getMap() {
        return map;
    }

    public void setMap(HashMap<Integer, Integer> map) {
        this.map = map;
    }
}
