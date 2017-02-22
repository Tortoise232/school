from copy import deepcopy
from domain.StudentClass import Student
from domain.StudentError import StudentError
from handler.StatHandler import StatHandler
from domain.UndoOps import AddOperation, RemoveOperation, UpdateOperation
class StudHandler(object):
    '''
    Handles operations with the students
    Functionalities:
    update student
    find student
    list all students
    add student
    remove students
    sort students alphabetically 
    sort students by grade (correlated with a list of assignments with the same description)
    '''


    def __init__(self, studrepo):
        '''
        creator for the student repository
        '''
        self._studrepo = studrepo
        self._undoop = []
        self._redoop = []
    
    def updateStud(self,studid):
        '''
        updates a student's name and group
        '''
        oldstud = deepcopy(self.findStud(studid))
        newstud = self._studrepo.updateById(studid)
        self._undoop.append(UpdateOperation(oldstud,newstud))
        self._redoop = []
    def findStud(self,studid):
        '''
        finds a student by the given ID
        '''
        return self._studrepo.findById(studid)   
    
    def listStud(self):
        #calls listing function in repository to return the list of strings representing the content of the repo
        return self._studrepo.listStud()
    
    def addStud(self):
        '''
        adds a new student to the repository
        calls add function in the repository
        '''
        print("Student Name:")
        tempName = input()
        print("Student ID:")
        tempID = input()
        print("Student Group:")
        try:
            tempGroup = int(input())
        except:
            raise StudentError("Invalid group!")
        newStud = Student(tempID,tempName,tempGroup)
        self._studrepo.add(newStud)
        self._undoop.append(AddOperation(newStud))
        self._redoop = []
        
    def sortStudentsABC(self,listStud,listAssign):
        '''
        Sorts a list of Student objects alphabetically
        input: listStud - list of students
        output: listStud - list of students (sorted)
        '''
        if len(listStud) <= 0 or len(listAssign) <= 0:
            raise StudentError("No students or no assignments")
        for counter in range ( 0 , len( listStud ) ):
            for counter2 in range ( counter , len( listStud ) ):
                if listStud[counter].getName() > listStud[counter2].getName():
                    aux = listStud[counter]
                    listStud[counter] = listStud[counter2]
                    listStud[counter2] = aux
        return listStud
    
    def findGradeByAssign(self,Student,listAssign):
        '''
        finds grade of each student by his assignments
        '''
        for counter in range (0, len(listAssign)):
            if Student.getID() == listAssign[counter].getID():
                return listAssign[counter].getGrade()
                      
    def statByAssignABC(self,assignrepo,desc):
        '''
        Function returns a list of strings that represent the students 
        and their respective grades that fit the description in alphabetical order
        intput: assignrepo - assignment repository
                desc - description of the assignment
        output: newList - list containing the students and their assignment grades
        '''
        tempStud = [] #represents the students in the list with the given assignment
        tempAssign = [] #represents the assignments
        for counter in range ( 0, len( assignrepo ) ):
            #extracts the students and assignment from repository
            if assignrepo._data[counter].getDesc() == desc:
                tempStud.append( self._studrepo.findById( assignrepo._data[counter].getID() ) )
                tempAssign.append( assignrepo._data[counter])
            
            tempStud = deepcopy( self.sortStudentsABC( tempStud ,desc) ) #sorts students alphabetically 
        newList = []#list of strings representing students and grades
        for counter in range(0, len (tempStud)):
            for counter2 in range(0, len (tempAssign)):
                if tempStud[counter].getID() == tempAssign[counter2].getID():
                    newList.append(str(tempStud[counter]) + " Grade " +str(tempAssign[counter2].getGrade()))
        return newList

    def statByAssignGr(self,assignrepo,desc):
        '''
        sorts students by the grade on a given assignment (by description)
        '''
        stathandler = StatHandler(assignrepo,self._studrepo)
        return stathandler.sortByAssignGrade(desc)
        
    def removeStud(self,stid):
        '''
        removes a student from the repository
        '''
        removed = self._studrepo.removeById(stid)
        self._undoop.append(RemoveOperation(removed))
        self._redoop = []
        
    def undo(self):
        if self._undoop == []:
            raise StudentError("No operations to undo")
        operation = self._undoop.pop()
        
        if isinstance(operation,AddOperation):
            self._studrepo.remove(operation.getObject())
            
        elif isinstance(operation,RemoveOperation):
            self._studrepo.add(operation.getObject())
        
        elif isinstance(operation,UpdateOperation):
            self._studrepo.remove(operation.getNewObject())
            self._studrepo.add(operation.getOldObject())
            
        self._redoop.append(operation)
        
        
    def redo(self):
        if self._redoop == []:
            raise StudentError("No operations to redo")
        operation = self._redoop.pop()
        
        if isinstance(operation,AddOperation):
            self._studrepo.add(operation.getObject())
            
        elif isinstance(operation,RemoveOperation):
            self._studrepo.remove(operation.getObject())
            
        elif isinstance(operation,UpdateOperation):
            self._studrepo.remove(operation.getOldObject())
            self._studrepo.add(operation.getNewObject())
        
        self._undoop.append(operation)
        
        