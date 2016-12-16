package model.interfaces;
import java.io.Serializable;

import model.interfaces.IDictionary;
public interface IExpression extends Serializable{
		public int evaluate(IDictionary<String,Integer> myDic, IHeap myHeap);
}


