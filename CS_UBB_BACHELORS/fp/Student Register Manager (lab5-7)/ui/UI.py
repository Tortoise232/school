from copy import deepcopy
from domain.StudentError import StudentError
from domain.AssignmentError import AssignmentError


class UI():


    def __init__(self,AssignHandler,StudHandler,LinkHandler):
        '''
        constructor for the UI class
        '''
        self._ashandler = AssignHandler
        self._sthandler = StudHandler
        self._linkhandler = LinkHandler
        self._undoswitch =[] # 0 for student operations, 1 for assignment operations
        self._redoswitch = []
    def showMain(self):
        '''
        Prints main menu
        '''
        print("MAIN MENU:")
        print("1 Add student")
        print("2 Add assignment")
        print("3 Find student by ID")
        print("4 Find assignments by ID")
        print("5 List students")
        print("6 List assignments")
        print("7 Remove student by ID")
        print("8 Remove assignment by ID")
        print("9 Update student by ID")
        print("10 Update assignment by ID")
        print("11 Sort students alphabetically by assignment (description)")
        print("12 Sort students by grade on an assignment (description)")
        print("13 Undo")
        print("14 Redo")
        print("0 Close application")
    
    def opt1(self):
        '''
        adds a student
        '''
        self._sthandler.addStud()
        print("Adding Successful")
        self._undoswitch.append(0)
        self._redoswitch = []
    def opt2(self):
        '''
        adds an assignment
        '''
        newassign = self._ashandler.addAssign()
        tempstud = self._sthandler.findStud(newassign.getID())
        if tempstud == None:
            self._ashandler.removeAssign(newassign.getID()) #removes object if there is no student to assign to
            raise StudentError("No student to assign to")
        else:
            self._linkhandler.makeLink(newassign,tempstud)
            print("Adding Successful")
        self._undoswitch.append(1)
        self._redoswitch = []
    def opt3(self):
        '''
        finds a student by ID
        '''
        print("Give  ID:")
        sid = input()
        if(len(self._sthandler._studrepo) == 0):
            raise StudentError ("No students in the list")
        print(self._sthandler.findStud(sid))        
    
    def opt4(self):
        '''
        finds an assignment by ID
        '''
        print("Give  ID:")
        kid = input()
        temp = deepcopy(self._ashandler.findAssign(kid))
        if(temp == None):
            raise StudentError("No assignments in the list")
        print(temp)  
    
    def opt5(self):
        '''
        lists all students
        '''
        tempList = self._sthandler.listStud()
        for counter in range(0,len(tempList)):
            print(str(tempList[counter]))
    
    def opt6(self):
        '''
        lists all assignments
        '''
        tempList = self._ashandler.listAssign()
        for counter in range(0,len(tempList)):
            print(str(tempList[counter])) 
            
    def opt7(self):
        '''
        removes a student and all his assignments/links
        '''
        print("Input student ID:")
        stid = input()
        student = self._sthandler.findStud(stid)
        dltlink = self._linkhandler.findLink(student)
        while dltlink != None:
            try:
                assignid = dltlink.getAssign().getKeyID()
                self._ashandler.removeAssign(assignid)
                self._linkhandler.removeLink(dltlink)
                dltlink = self._linkhandler.findLink(student)
            except:
                break
        self._sthandler.removeStud(stid)
        print("Removal Successful")
        self._undoswitch.append(0)
        self._redoswitch = []
    def opt8(self):
        '''
        removes an assignment by ID
        '''
        print("Input assignment ID:")
        kid = input()
        dlassign = self._ashandler.findAssign(kid)
        self._ashandler.removeAssign(kid)
        self._linkhandler.removeLink(self._linkhandler.findLink(dlassign))
        print("Removal Successful")      
        self._undoswitch.append(1)
        self._redoswitch = []        
    def opt9(self):
        '''
        updates a students name and group by ID
        '''
        print("Give student ID:")
        studid = input()
        self._sthandler.updateStud(studid)
        print("Update Successful")
        self._undoswitch.append(0)
        self._redoswitch = []
    def opt10(self):
        '''
        updates assignment ID
        '''
        print("Give Assignment ID:")
        kid = input()
        self._ashandler.updateAssign(kid)
        print("Update Successful")
        self._undoswitch.append(1)
        self._redoswitch = []
    def opt11(self):
        '''
        sorts students alphabetically by assignment description
        '''
        print("Give Assignment Description:")
        tempList = self._sthandler.statByAssignABC(self._ashandler._assignrepo,input())
        for counter in range (0,len(tempList)):
            print(tempList[counter])
            
    def opt12(self):
        '''
        sorts students by grade on an assignment
        '''
        print("Give Assignment Description:")
        tempList = self._sthandler.statByAssignGr(self._ashandler._assignrepo,input()) 
        for counter in range(0, len(tempList)):
            print(tempList[counter])
    
    def opt14(self):
        try:
            switch = self._undoswitch.pop()
        except:
            raise StudentError("No operation to undo!")
        if switch == 0:
            self._sthandler.undo()
        else:
            self._ashandler.undo()
            
        self._redoswitch.append(switch)
        
    def opt15(self):
        try:
            switch = self._redoswitch.pop()
        except:
            raise StudentError("No operation to redo!")
        if switch == 0:
            self._sthandler.redo()
        elif switch == 1:    
            self._ashandler.redo()
        self._undoswitch.append(switch)
            
    def takeInput(self):
        '''
        Takes input and calls controllers
        '''
        
        while True:
            self.showMain()
            opt = input()
               
            if opt == '1':
                self.opt1()    
            elif opt == '2':
                self.opt2() 
            elif opt == '3':
                self.opt3() 
            elif opt == '4':
                self.opt4()
            elif opt == '5':
                self.opt5()
            elif opt == '6':
                self.opt6()    
            elif opt == '7':
                self.opt7()
            elif opt == '8':
                self.opt8()
            elif opt =='9':
                self.opt9()
            elif opt =='10':
                self.opt10()
            elif opt == '11':
                self.opt11()
            elif opt == '12': 
                self.opt12()   
            elif opt == '15': #used to show links, lol
                templist = self._linkhandler.printLinks()
                for cr in range (0,len(templist)):
                    print(str(templist[cr]))
            elif opt =='13':
                self.opt14()
            elif opt =='14':
                self.opt15()
                    
            elif opt == '0':
                return 0
            else:
                raise StudentError("Invalid Command")
            
            self._ashandler._assignrepo.writetofile()
            self._sthandler._studrepo.writetofile()    
    def loop(self):
        '''
        loops the take input menu
        '''
        try:
            try: 
                self.takeInput()
            except AssignmentError as e:
                print(e)
                self.loop()
        except StudentError as e:
            print(e)
            self.loop()