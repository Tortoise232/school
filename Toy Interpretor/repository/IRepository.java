package repository;
import java.io.IOException;
import java.io.Serializable;

import model.*;

public interface IRepository extends Serializable{
	public void addPrgState(PrgState p);
	public PrgState getCurrentPrg();
	public void logPrgStateExec()throws IOException;
	public void serializeToFile(String filePath);
	public void deserializeFromFile(String filePath);
}
