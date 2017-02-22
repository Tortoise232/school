from domain.StudentError import StudentError
from domain.StudentClass import Student
class StudentRepo():
    '''
    Class meant to store the Student Objects
    Manages:
     -adding students 
     -listing students 
     -finding students by id
    '''
    def __init__(self): 
        self._data = []
     
    def __len__(self):
        return len(self._data)
    
    def findById(self,idstring):
        '''
        finds a student by his ID
        input idstring - the ID of the student we are looking for
        returns student 
        '''
        for counter in range (0,len(self)):
            if self._data[counter].getID() == idstring:
                return self._data[counter]
        
    def add(self,Student): 
        '''
        adds a new student to the repository
        input: Student object
        '''
        if self.findById(Student.getID())!= None:
            raise StudentError("Duplicate ID")
        else:
            self._data.append(Student)
            
    def listStud(self):
        '''
        returns all the students from the repository in a list of strings 
        output: list of students
        '''
        templist = []
        for counter in range(0,len(self)):
            templist.append(str(self._data[counter]))         
        return templist
    
    def removeById(self,idstring):
        '''
        removes a student from the repo based on the id
        input: the ID of the student wanting to be removed
        output: the Student object that has been removed
        '''
        temp = None
        for counter in range (0,len(self._data)) :
            if self._data[counter-1].getID() == idstring:
                temp = self._data.pop(counter-1)
        if temp == None:
            raise StudentError("Student to be removed not found!")
        else:
            return temp
        
    def remove(self,Student):
        '''
        removes a student based on it's object. uses removeById method
        input: Student - the object to be removed
        no output
        '''
        if self.findById(Student.getID()) == None:
            raise StudentError("Student ID not found; cannot delete")
        else:
            return(self.removeById(Student.getID()))
            
    def findIndex(self,Student):
        '''
        finds the index of the Student object
        output: the index in the repository (of the Student object)
        '''

        for counter in range (0,len(self)):
            if self._data[counter].getID() == Student.getID():
                return counter
            
    def updateById(self,studid):
        '''
        updates certain info of a student
        '''
        a = self.findIndex(self.findById(studid))
        if a == None or self.findById(studid) == None:
            raise StudentError("Student not found")
        print("Input new name:")
        self._data[a].setName(input())
        print("Input new group:")
        self._data[a].setGroup(int(input()))
        return self._data[a]
        
    def writetofile(self):
        '''
        saves the repository to a file
        '''
        f = open("stud.txt","w")
        for counter in self._data:
            f.write(counter.getID())
            f.write(";")
            f.write(counter.getName())
            f.write(";")
            f.write(str(counter.getGroup()))
            f.write(";\n")
        f.write("end")
        f.close()    
    
    def readfromfile(self):
        '''
        loads the repository from the file
        '''
        f = open("stud.txt","r")
        raw = f.readline().split(sep=";")
        while  raw[0] != "end\n" and raw[0] != "end" and len(raw) >= 3:
            newid = raw[0]
            newname = raw[1]
            newgroup = int(raw[2])
            newstud = Student(newid,newname,newgroup)
            self.add(newstud)
            raw = f.readline().split(sep=";")            