package model.interfaces;

import java.io.Serializable;
import java.util.*;

public interface IHeap extends Serializable{
	public HashMap<Integer,Integer> getMap();
	public void setMap(HashMap<Integer,Integer> map);
	public int newElem(int value);
	public int readHeap(int  location);
	public int writeHeap(int location, int newValue);
	public int generateLocation();
	public String toString();
}
