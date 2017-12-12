package com.company;

/**
 * Created by Petean Mihai on 11/13/2017.
 */
public class Tuple {
    public int x;
    public int y;

    @Override
    public String toString() {
        return "{" +
                 x +
                "," +  y +
                '}';
    }

    public Tuple(int x, int y){
        this.x = x;
        this.y = y;
    }
}
