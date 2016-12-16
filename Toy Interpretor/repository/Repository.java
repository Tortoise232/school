package repository;

import java.util.ArrayList;
import model.PrgState;
import java.io.*;

public class Repository implements IRepository{
	protected ArrayList<PrgState> listOfStates;
	protected String logPath = "log.txt";
	public Repository(){
		this.listOfStates = new ArrayList<PrgState>();
	}
	
	@Override
	public void addPrgState(PrgState p) {
		listOfStates.add(p);
	}

	@Override
	public PrgState getCurrentPrg() {
		return listOfStates.get(listOfStates.size()-1);
	}
	@Override
	public void logPrgStateExec() throws IOException{
		PrintWriter logFile;
		logFile = new PrintWriter(new BufferedWriter(new FileWriter(logPath, true)));
		logFile.write(this.getCurrentPrg().toString() + "\n");
		logFile.close();
	}

	@Override
	public void serializeToFile(String filePath) {
		
		try{
		FileOutputStream fileOut = new FileOutputStream(filePath);
		         ObjectOutputStream out = new ObjectOutputStream(fileOut);
		         try{
		        	 out.writeObject(listOfStates.get(0));
		         }catch(NotSerializableException e){
		        	 //too bad there isn't any serialization for buffered readers, right?
		         }
		         out.close();
		         fileOut.close();
		}catch(IOException e){
			e.printStackTrace();
		}
		
	}

	@Override
	public void deserializeFromFile(String filePath) {
		 PrgState prog = null;
		
	      try {
	         FileInputStream fileIn = new FileInputStream(filePath);
	         ObjectInputStream in = new ObjectInputStream(fileIn);
	         try {
				prog = (PrgState) in.readObject();
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
	         in.close();
	         fileIn.close();
	      }catch(IOException i) {
	         i.printStackTrace();
	         
	         return;
	      }	
		 
	      listOfStates.clear();
	      listOfStates.add(prog);
	}
	
}
