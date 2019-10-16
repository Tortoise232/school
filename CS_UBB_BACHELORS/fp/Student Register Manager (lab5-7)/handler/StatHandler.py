from copy import deepcopy

class StatHandler(object):
    '''
    Class meant to handle statistic obtaining
    functionalities:
    sorts a list of assignment objects by their grade
    computes a list of strings showing a list of students and their grading on an assignment 
    '''


    def __init__(self, asrepo, strepo):
        self._asrepo = asrepo
        self._studrepo = strepo
    
    def sortAssignByGrade(self,assignList):
        '''
        Sorts assignment objects from a list by their grade
        '''
        #worst kind of sort, but whatever.
        for counter in range (0, len(assignList)):
            for counter2 in range (counter, len(assignList)):
                if assignList[counter].getGrade() < assignList[counter2].getGrade():
                    aux = assignList[counter]
                    assignList[counter] = assignList[counter2]
                    assignList[counter2] = aux  
        return assignList 
    
    def sortStudentsByAssign(self,studList,assignList):
        tempList = []
        for counter in range(0, len(assignList)):
            for counter2 in range(0, len(studList)):
                if studList[counter2].getID() == assignList[counter].getID():
                    #if an assignment of the students id matches, print that student and his grade, on the sorted list
                    tempList.append(str(studList[counter2])+" Grade " + str(assignList[counter].getGrade()))
        return tempList #return list of strings representing the sorted list of students on the assignment
    
    def sortByAssignGrade(self, desc):
        '''
        Sorts the repository of students by one of their assignments (identified by its description)
        desc - description of the input
        '''
        studList =[]
        assignList =[]
        #fills the lists 
        for counter in range (0, len(self._asrepo)):
            if self._asrepo._data[counter].getDesc() == desc:
                assignList.append(self._asrepo._data[counter])
                studList.append(self._studrepo.findById(self._asrepo._data[counter].getID()))
        assignList = deepcopy(self.sortAssignByGrade(assignList))
        return self.sortStudentsByAssign(studList, assignList)    
                