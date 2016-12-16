package model;
import java.io.*;

import model.interfaces.*;
public class PrgState implements Serializable{
	private static final long serialVersionUID = -5116545090005092303L;
	public  IDictionary<String,Integer> symbolTable;
	protected  IStak<IStatement> stack;
	public  IList<Integer> output;
	protected  FileTable fileTable;
	public IHeap heap;
	public void setStack(IStak<IStatement> stack){
		this.stack = stack;
	}
	
	public void setTable(IDictionary<String,Integer> dictionary){
		this.symbolTable = dictionary;
	}
	
	public void setOutput(IList<Integer> output){
		this.output = output;
	}
	
	public void setFileTable(FileTable table){
		this.fileTable = table;
	}
	
	public void setHeap(IHeap newHeap){
		this.heap = newHeap;
	}
	
	public IHeap getHeap(){
		return this.heap;
	}
	
	public IStak<IStatement> getStack(){
		return stack;
	}
	
	public IDictionary<String,Integer> getTable(){
		return symbolTable;
	}
	
	public IList<Integer> getOutput(){
		return output;
	}

	public FileTable getFileTable(){
		return fileTable;
	}
	
	public PrgState(){
		this.heap = new MyHeap();
		this.symbolTable = new MyDictionary();
		this.stack = new MyStack();
		this.output = new MyList();
		this.fileTable = new FileTable();
	}
	
	public PrgState(IDictionary<String,Integer> dict, 
					IStak<IStatement> stack, 
					IList<Integer> output, 
					FileTable fileTable,
					IHeap heap){
		this.heap = heap;
		this.symbolTable = dict;
		this.stack = stack;
		this.output = output;
		this.fileTable = fileTable;
	}
	
	@Override 
	public String toString(){
		String result = new String();
		result += "Stack: " + stack + "\n";
		result += "SymbolTable: " + symbolTable + "\n";
		result += "Output: " + output + "\n";
		result += "FileTable: " + fileTable + "\n";
		result += "Heap" + heap + "\n";
		return result;
	}
	
}
