package com.company;

/**
 * Created by alex on 10/11/16.
 */
public class Transition {

    private final String value;
    private final String finalState;
    private final String initialState;

    public Transition(String initState, String finalState, String value) {
        this.initialState = initState;
        this.finalState = finalState;
        this.value = value;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Transition)) return false;

        Transition that = (Transition) o;

        if (value != null ? !value.equals(that.value) : that.value != null) return false;
        if (finalState != null ? !finalState.equals(that.finalState) : that.finalState != null) return false;
        return initialState != null ? initialState.equals(that.initialState) : that.initialState == null;
    }

    public String getValue() {
        return value;
    }

    public String getFinalState() {
        return finalState;
    }

    public String getInitialState() {
        return initialState;
    }

    @Override
    public String toString() {
        return "Transition{" +
                "value='" + value + '\'' +
                ", finalState='" + finalState + '\'' +
                ", initialState='" + initialState + '\'' +
                '}';
    }
}
