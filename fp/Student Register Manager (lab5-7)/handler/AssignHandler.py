
from domain.AssignClass import Assignment
from domain.UndoOps import AddOperation
from domain.UndoOps import RemoveOperation
from domain.UndoOps import UpdateOperation
from domain.AssignmentError import AssignmentError
from copy import deepcopy
class AssignHandler():
    '''
    Handles operations regarding the  assignment repository
    Functionalities:
    finds assignments
    lists assignments
    add assignment
    remove assignment
    update assignment
    '''


    def __init__(self, assignrepo):
        '''
        constructor for the controller
        '''
        self._assignrepo = assignrepo
        self._undoop = []
        self._redoop = []
        
    def updateAssign(self,kid):
        '''
        Updates an Assignment, finding it by its description
        '''
        oldobj = deepcopy(self._assignrepo.findById(kid))
        newobj = self._assignrepo.updateByID(kid)
        self._undoop.append(UpdateOperation(oldobj,newobj))
        self._redoop = []
        
    def findAssign(self,kid):
        '''
        Finds the assignment with a given id
        '''
        return self._assignrepo.findById(kid)
        
    def listAssign(self):
        '''
        lists all assignments
        '''
        return self._assignrepo.list()
    
    def addAssign(self):
        '''
        adds a new assignment
        '''
        print("Input ID of the Assignment:")
        newKID = input()
        print("Input corresponding student ID:")
        newID = input()
        print("Input assignment description:")
        newDesc = input()
        print("Input assignment deadline dd/mm/yyyy:")
        newDate = input()
        print("Input assignment grade:")
        try:
            newGrade = int(input())
        except:
            raise AssignmentError("Invalid grade!")
        newAssign = Assignment(newID,newDesc,newDate,newGrade,newKID)
        self._assignrepo.add(newAssign)
        self._undoop.append(AddOperation(newAssign))
        self._redoop = []
        return newAssign
        
    def removeAssign(self,kid): 
        '''
        removes an assignment
        '''
        removedobj = self._assignrepo.removeById(kid)
        self._undoop.append(RemoveOperation(removedobj))    
        self._redoop = []
    
    def undo(self):
        '''
        undoes the last operation
        '''
        if self._undoop == []:
            raise AssignmentError("No operations to undo")
        operation = self._undoop.pop()
        
        if isinstance(operation,AddOperation):
            self._assignrepo.removeById(operation.getObject().getKeyID())
            
        elif isinstance(operation,RemoveOperation):
            self._assignrepo.add(operation.getObject())
        
        elif isinstance(operation,UpdateOperation):
            self._assignrepo.removeById(operation.getNewObject().getKeyID())
            self._assignrepo.add(operation.getOldObject())
            
        self._redoop.append(operation)
        
    
    def redo(self):
        '''
        redoes the last operation
        '''
        if self._redoop == []:
            raise AssignmentError("No operations to redo")
        operation = self._redoop.pop()
        
        if isinstance(operation,AddOperation):
            self._assignrepo.add(operation.getObject())
            
        elif isinstance(operation,RemoveOperation):
            self._assignrepo.removeById(operation.getObject().getKeyID())
            
        elif isinstance(operation,UpdateOperation):
            self._assignrepo.removeById(operation.getOldObject().getKeyID())
            self._assignrepo.add(operation.getNewObject())
        
        self._undoop.append(operation)
        
        
    
            