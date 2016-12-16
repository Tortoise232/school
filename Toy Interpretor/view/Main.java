package view;
import controller.Controller;
import tests.*;
import repository.Repository;
import model.*;
import model.expressions.*;
import model.interfaces.*;
import model.statements.*;
public class Main {

	public static void main(String[] args) {
		System.out.println("STARTING PROGRAM");
		IExpression daddysfirstexpression = new VariableExpression("v");
		IStatement printState = new PrintStatement(daddysfirstexpression);
		IExpression constExpr = new ConstExpression(2);
		IStatement assignState = new AssignStatement("v",constExpr);
		IStatement compState = new CompoundStatement(assignState, printState);
		IStatement openFileState = new openRFile("file.txt","VarFromFile");
		IStatement newStuff = new newStatement("Valcea",constExpr);
		IStatement newStuff2 = new newStatement("Eroina",constExpr);
		IStatement readFile = new readFile(new ConstExpression(0),"MyVar");
		MyHeap heap  = new MyHeap();
		MyStack<IStatement> newStak = new MyStack<IStatement>();
		MyDictionary<String, Integer> newDict = new MyDictionary<String, Integer>();
		MyList<Integer> newList = new MyList<Integer>();
		FileTable newFileTable = new FileTable();
		PrgState newPrgState = new PrgState(newDict, newStak, newList, newFileTable, heap);
		Repository newRepo = new Repository();
		newStak.push(new WhileStatement(new AssignStatement("v",new ConstExpression(0)),daddysfirstexpression));
		newStak.push(newStuff);
		newStak.push(newStuff2);
		newStak.push(compState);
		newStak.push(assignState);
		newRepo.addPrgState(newPrgState);
		newStak.push(readFile);
		newStak.push(openFileState);
		Controller myController = new Controller(newRepo);
		
		myController.executeAll();
		myController.serialize("someplace");
		
		myController.deserialize("someplace");
		System.out.println(myController.getRepo().getCurrentPrg());
		testExpressions testE = new testExpressions();
		testStatements testS= new testStatements();
		testE.run();
		testS.run();
		
	}

}
