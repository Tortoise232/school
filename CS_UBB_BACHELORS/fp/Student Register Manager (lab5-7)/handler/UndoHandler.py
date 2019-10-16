from handler import LinkHandler
from handler import AssignHandler
from handler import StudHandler

class UndoHandler(object):
    '''
    Handles the undo operations 
    '''


    def __init__(self):
        self._undoop = []
        self._redoop = []
    
    def recOperation(self,operation):
        self._operations.append(operation)
    
    def undo(self):
        if self._undoop == []:
            return False
        for controller in self._operations[-1]:
            controller.undo()   
            
            
        return True
    
    def redo(self):
        
    