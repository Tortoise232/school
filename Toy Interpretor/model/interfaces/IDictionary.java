package model.interfaces;

import java.io.Serializable;
import java.util.ArrayList;

public interface IDictionary<T,V> extends Serializable{
		public void add(T name, V value);
		public boolean contains(T name);
		public boolean containsValue(V value);
		public void setValue(T name, V value);
		public V getValue(T name);
		public String toString();
		public void remove(T name);
		public ArrayList<V> getValues();
		
}

