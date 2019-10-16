from domain.StudentError import StudentError
from domain.AssignClass import Assignment
from domain.LinkClass import Link
from domain.StudentClass import Student
class LinkHandler(object):
    '''
    This handles all the links between students and assignments
    '''


    def __init__(self,studrepo,assignrepo,linkrepo,idcounter):
        '''
        constructor for the link handler class
        '''
        self._assignrepo = assignrepo
        self._studrepo = studrepo
        self._linkrepo = linkrepo
        self._idcounter = idcounter
        self._undoop = []
        
    def getIDcounter(self):
        '''
        returns the id counter responsable for indexing links
        '''
        return self._idcounter
    
    def incID(self):
        '''
        increments the id counter responsable for indexing links
        '''
        self._idcounter = self._idcounter + 1
        
    
    def makeLink(self,Assignment,Student):
        '''
        creates a new link between an assignment and a student
        also adds link to the repo
        '''
        newLink = Link(Student,Assignment,self._idcounter)
        self.incID()
        self._linkrepo.add(newLink)
        
    def printLinks(self):
        '''
        prints all the strings representing the links between students and assignments
        '''
        return self._linkrepo.printRepo()
    
    def findLink(self,Object):
        '''
        finds the first link containing the object given (student or assignment)
        '''
        self._linkrepo
        if type(Object) == Student:
            return self._linkrepo.findByStud(Object)
        elif type(Object) == Assignment:
            return self._linkrepo.findByAssign(Object)
        
    def removeLink(self,Link):
        '''
        removes a link
        '''
        self._linkrepo.removeLink(Link)
        
    def undo(self):
        if self._undoop < 0:
            raise StudentError("No operations to undo")
        operation = self._undoop.pop()
        if isinstance(operation,AddLink):
            operation.getRepo().removeLink(operation.getLink())
        #elif isinstance(operation,RemoveLink):
            #operation.
                
        
        
        