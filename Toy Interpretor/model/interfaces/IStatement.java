package model.interfaces;

import java.io.Serializable;

import model.PrgState;

public interface IStatement extends Serializable{
	public PrgState execute(PrgState p);
	
}
