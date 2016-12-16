package controller;
import java.io.IOException;
import java.io.NotSerializableException;
import java.util.*;
import java.util.Map.Entry;
import java.util.stream.*;
import model.interfaces.*;

import model.*;
import repository.IRepository;
public class Controller {
	protected IRepository repo;
	public IHeap conservativeGarbageCollector(
			IDictionary<String,Integer> symbolTable, 
			IHeap heap){
	IHeap result = new MyHeap();
	Stream goodAddresses = ( heap.getMap().entrySet().stream()
			 .filter(e->symbolTable.getValues().contains( e.getKey() ) ));
	Iterator<Entry<Integer,Integer>> addressesIterator = (Iterator<Entry<Integer,Integer>>)goodAddresses.iterator();
	while(addressesIterator.hasNext()){
		Entry<Integer,Integer> a = addressesIterator.next();
		result.getMap().put(a.getKey(), a.getValue());
	}
	return result;

}
	
	public Controller(IRepository repo){
		this.repo = repo;
		
	}
	
	public void executeOneStep(PrgState p){
		IStak<IStatement> exec = p.getStack();
		if(!exec.isEmpty()){
			IStatement statement = exec.pop();
			statement.execute(p);
		}
	}
		
	public void executeAll(){
		PrgState myProgState = repo.getCurrentPrg();
		while(!myProgState.getStack().isEmpty()){
			executeOneStep(myProgState);
			myProgState.setHeap(conservativeGarbageCollector(myProgState.symbolTable,myProgState.heap));
			try {
				repo.logPrgStateExec();
			} 
			catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	public void serialize(String filePath){
		this.repo.serializeToFile(filePath);
		}
	
	public void deserialize(String filePath){
		this.repo.deserializeFromFile(filePath);
	}
	
	public IRepository getRepo(){
		return this.repo;
	}

	
	
}
