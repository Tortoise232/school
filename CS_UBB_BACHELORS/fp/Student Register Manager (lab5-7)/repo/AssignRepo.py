from domain.StudentError import StudentError
from domain.AssignmentError import AssignmentError
from domain.AssignClass import Assignment


class AssignRepo():
    '''
    Class meant to store the Assignment objects, manages adding and finding
    '''
    
    def __init__(self):
        '''
        constructor for the repository, a list of assignment objects
        '''
        self._data = []
        
    def __len__(self):
        '''
        returns the length of the repository
        '''
        return len(self._data)
    
    def findById(self,idstring):
        '''
        returns the assignment with the given ID
        '''
        for counter in range (0,len(self)):
            if self._data[counter].getKeyID() == idstring:
                return self._data[counter]
    
    def removeById(self,idstring):
        '''
        removes the assignment having the given ID
        '''
        for counter in range(0, len(self)):
            if self._data[counter].getKeyID()== idstring:
                return self._data.pop(counter)        
        raise StudentError("Assignment not found")
    
    def findByStudID(self,idstring):
        '''
        returns the assignment with the given student id
        '''
        for counter in range(0, len(self)):
            if self._data[counter].getID()== idstring:
                return self._data.pop(counter)
        raise StudentError("Assignment not found")
    
    def add(self,Assignment):
        '''
        adds an assignment 
        '''
        if self.findById(Assignment.getKeyID()) != None:
            print(Assignment.getKeyID())
            raise AssignmentError("Duplicate ID")
        else:
            self._data.append(Assignment)
        
    def findByDes(self, descr):
        '''
        finds an assignment by a description
        warning!!! - returns only the 1st assignment with said description
        returns the index of said assignment
        '''
        templist = []
        for counter in range(0,len(self)):
            if self._data[counter].getDesc() == descr:
                templist.append(self._data[counter])
        return templist
             
    def updateByID(self,kid):
        temp = self.findById(kid)
        if temp == None:
            raise StudentError("No assignment found")
        '''
        Updates the deadline, grade and description of an assignment, finding it by its ID
        '''
        print("Input new Deadline:")
        temp.setDead(input())
        print("Input new Grade:")
        temp.setGrade(int(input()))
        print("Input new Description")
        temp.setDesc(input())
        return temp 
        
    def list(self):
        '''
        Returns a list of strings representing all the data inside the repository
        '''    
        templist = []
        for counter in range(0,len(self)):
            templist.append(str(self._data[counter]))         
        return templist   
    
    def writetofile(self):
        '''
        saves the repository to a file
        '''
        f = open("assign.txt","w")
        for counter in self._data:
            f.write(counter.getID())
            f.write(";")
            f.write(counter.getDesc())
            f.write(";")
            f.write(counter.getDead())
            f.write(";")
            f.write(str(counter.getGrade()))
            f.write(";")
            f.write(str(counter.getKeyID()))
            f.write(";\n")
        f.write("end")
        f.close()
        
    def readfromfile(self):
        '''
        loads the repository from the file
        '''
        f = open("assign.txt","r")
        raw = f.readline().split(sep=";")
        while  raw[0] != "end\n" and raw[0] != "end" and len(raw) >= 5:
            newid = raw[0]
            newdesc = raw[1]
            newdead = raw[2]
            newgrade = int(raw[3])
            newkid = raw[4]
            newassign = Assignment(newid,newdesc,newdead,newgrade,newkid)
            self.add(newassign)
            raw = f.readline().split(sep=";")