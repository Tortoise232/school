package model.interfaces;

import java.io.Serializable;
import java.util.Iterator;

public interface IList<E> extends Serializable{
	public void add(E elem);
	public Iterator<E> getAll();
	
}	
