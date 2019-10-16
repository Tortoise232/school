
from domain.StudentError import StudentError
class Student(object):
    '''
    Student class, contains:
    studid - student id, a string (should be numerical?)
    name - student name, a string
    group - student group, integer
    class contains initiate function, invalid data checking get/setters, string conversion 
    '''
  

    def __init__(self,studid,name,group):
        if len(studid) == 0 :
            raise StudentError("Bad ID")
        if len(name) == 0:
            raise StudentError("Invalid Name")
        self.studid = studid
        self.name = name 
        self.group = group 
     
    def __repr__(self):
        '''
        Returns a string consisting of the data of the student
        '''
        return "Name: " + self.name +" ID: "+ self.studid + " Group: " + str(self.group)       

    def __str__(self):
        '''
        Returns a string consisting of the data of the student
        '''
        return "Name: " + self.name +" ID: "+ self.studid + " Group: " + str(self.group)       

    def getID(self):
        '''
        Returns the ID of a given student
        '''
        return self.studid
    
    def setID(self,newid):
        '''
        Updates the ID of a given student, replacing the ID with the string newid
        '''
        if len(newid) == 0:
            raise StudentError("Bad ID")
        self.studid = newid
 
    def getName(self):
        '''
        Returns the name of a given student
        '''
        return self.name
    
    def setName(self,newname):
        '''
        Updates the name of a given student, replacing the name of this student with the string newname
        '''       
        if len(newname) == 0:
            raise StudentError("Invalid Name")
        self.name = newname
        
    def getGroup(self):
        '''
        Returns the group of a given student (int)
        '''
        return self.group
    
    def setGroup(self,newgroup):
        '''
        Updates the group of a given student, replacing the group with the newgroup int
        '''
        self.group = newgroup
    
    
         
         
    
        