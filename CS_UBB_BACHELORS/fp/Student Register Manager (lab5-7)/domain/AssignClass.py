
from domain.AssignmentError import AssignmentError
class Assignment(object):
    '''
    Assignment class, contains
    studid - string representing student id
    description - string representing task description 
    '''

    
    def __init__(self,studid,description,deadline,grade,kid):
        '''
        Initialises the object with it's attributes,
        checks for missing id's or invalid ( <=0 ) grades
        '''
        
        if len(studid) == 0:
            raise AssignmentError("Bad ID")
        if  grade <= 0:
            raise AssignmentError("Invalid Grade")

        self.studid = studid
        self.description = description
        self.deadline = deadline
        self.grade = grade
        self.kid = kid #the key id of the assignmnet
        
    def __repr__(self):
        '''
        returns a string representing the information of an assignment
        '''
        return "Student ID: " + self.studid + " Description: " + self.description + " Deadline: " + self.deadline + " Grade: " + str(self.grade)
    def __str__ (self):
        '''
        returns a string representing the information of an assignment
        '''
        return "Student ID: " + self.studid + " Description: " + self.description + " Deadline: " + self.deadline + " Grade: " + str(self.grade)
    def getKeyID(self):
        '''
        reutrns the ID of the assignment
        '''
        return self.kid #cannot be set, i guess
    
    def setKeyID(self,kid):
        self.kid = kid
    
    def getID(self):
        '''
        gets student id
        '''
        return self.studid
    
    def setID(self,newid):
        '''
        sets student id
        '''
        if len(newid) == 0:
            raise AssignmentError("Bad ID")
        self.studid = newid
    
    def getDesc(self):
        '''
        gets assignment description
        '''
        return self.description
    
    def setDesc(self, newdesc):
        '''
        updates description of the assignment
        '''
        self.description = newdesc
        
    def getDead(self):
        '''
        obtains the deadline of the given assignment
        '''
        return self.deadline
    
    def setDead(self, newdead):
        '''
        updates the deadline of a given assignment by the given "newdead" string
        '''
        self.deadline = newdead
    
    def getGrade(self):
        '''
        obtains the grade of the given assignment
        '''
        return self.grade
    
    def setGrade(self,newgrade):
        '''
        updates the grade of a given assignment
        '''
        if newgrade <= 0:
            raise AssignmentError("Invalid Grade")
        self.grade = newgrade
        
    
    