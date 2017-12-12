package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

/**
 * Created by Petean Mihai on 12/11/2017.
 */
public class FiniteAutomaton {
    private ArrayList<String> alphabet = new ArrayList<>();

    private ArrayList<String> states = new ArrayList<>();
    private List<Transition> transitions = new ArrayList<>();


    private String initialState;
    private ArrayList<String> finalStates = new ArrayList<>();


    public FiniteAutomaton(String filename) throws FileNotFoundException {
        readFile(filename);
    }

    private void readFile(String filename) throws FileNotFoundException {
        Scanner s = new Scanner(new File(filename));
        String[] rawStates;
        rawStates = s.nextLine().split(" ");
        for(String state: rawStates)
            states.add(state);


        String[] rawStateValues;
        rawStateValues = s.nextLine().split(" ");
        List<Integer> statuses = new ArrayList<>();

        for (String status : rawStateValues) {
            statuses.add(Integer.parseInt(status));
        }


        for (int i = 0; i < states.size(); i++) {
            if (statuses.get(i) == 0) {
                initialState = states.get(i);
            } else if (statuses.get(i) == 1) {
                finalStates.add(states.get(i));
            }
        }

        String[] rawTransition = null;
        do {
            rawTransition = s.nextLine().split(" ");
            transitions.add(new Transition(rawTransition[0], rawTransition[1], rawTransition[2]));
            alphabet.add(rawTransition[2]);
        }while(rawTransition != null);
    }

    public boolean checkSequence(String sequence) {
        String currentState = this.initialState;
        String finalState = "";
        for (int i = 0; i < sequence.length(); ++i) {

            String character = sequence.substring(i, i+1), next = "";

            for (Transition transition : transitions) {
                if ((transition.getInitialState() ==  currentState) && (transition.getValue() == character)) {
                    next = transition.getFinalState();
                    break;
                }
            }

            if (next.length() == 0)
                return false;

            if (finalStates.contains(next) && i == sequence.length() - 1)
            {
                finalState = next;
                break;
            }

            currentState = next;
            finalState = next;
        }

        return finalStates.contains(finalState);
    }
}
