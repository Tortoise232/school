

class LinkRepo(object):
    '''
    Handles a repository of links between Students and Assignments
    '''


    def __init__(self):
        '''
        Constructor for the student-assignment linker
        '''
        self._data = []
        
            
    def __len__(self):
        '''
        returns the length of the repository
        '''
        return len(self._data)
    
    def add(self,Link):
        '''
        adds the given link object to the repository
        '''
        self._data.append(Link)
              
    
    def printRepo(self):
        '''
        returns a list containing strings representing the links of students/homeworks
        '''
        templist = []
        for cr in range (0, len(self)):
            templist.append(str(self._data[cr]))
        return templist  
    
    def findByStud(self,Student):
        '''
        finds a link by a student
        '''
        for cr in range(0,len(self)):
            if self._data[cr].getStud() == Student:
                return self._data[cr]
    
    def findByAssign(self,Assign):
        '''
        finds a link by an assignment
        '''
        for cr in range(0,len(self)):
            if self._data[cr].getAssign() == Assign:
                return self._data[cr]
            
    def removeLink(self,Link):
        '''
        removes a link object from the repo
        '''
        for cr in range (1,len(self._data)):
            if Link == self._data[cr]:
                self._data.pop(cr)
            