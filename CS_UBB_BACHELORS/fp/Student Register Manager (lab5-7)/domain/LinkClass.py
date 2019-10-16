

class Link(object):
    '''
    A link between one student and one assignment
    '''
    

    def __init__(self, stud, assign,lid):
        '''
        Builds the link between student and assignment
        '''
        self._stud = stud
        self._assign = assign
        self._ID = lid
    
    
    def getStud(self):
        '''
        returns the student of the link
        '''
        return self._stud
    
    def getAssign(self):
        '''
        returns the assignment of the link
        '''
        return self._assign

    def getID(self):
        '''
        returns the id of the link between student and assignemnt
        '''
        return self._ID
    
    def __str__(self):
        '''
        returns the repository as a list of strings containing the data of the link objects
        '''
        tempstr = self.getStud().getName() + " has the assignment: " + str(self.getAssign())    
        return tempstr
    
    def __repr__(self):
        '''
        returns the repository as a list of strings containing the data of the link objects
        '''
        tempstr = str(self.getStud()) + " has the assignment " + str(self.getAssign())    
        return tempstr
        
    