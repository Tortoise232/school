from domain.StudentClass import Student
from repo.StudentRepo import StudentRepo
from repo.AssignRepo import AssignRepo
from domain.AssignClass import Assignment
from repo.LinkRepo import LinkRepo
from domain.LinkClass import Link
import unittest

class Tests(unittest.TestCase):
    def testStudentClass(self):
        a = Student("1","Joe",916) #real professional testing right here, folks.
        assert a.getID() == "1"
        assert a.getName() == "Joe"
        assert a.getGroup() == 916
        a.setGroup(69)
        a.setID("69") 
        a.setName("Bob")
        assert a.getID() == "69"
        assert a.getName() == "Bob"
        assert a.getGroup() == 69
         
    def testStudentRepo(self):
        a = Student("2","John",100)
        b = StudentRepo()
        assert len(b) == 0
        b.add(a)
        assert len(b) == 1
        a = Student("3","Picks",50)
        b.add(a)
        assert len(b) == 2
        b.remove(a)
        assert len(b) == 1
        b.add(a)
        assert b.findById("3").getName() == "Picks"
            
    def testAssignClass(self):
        a = Assignment("1","hello","world",1,1)
        assert a.getDead() == "world"
        assert a.getDesc() == "hello"
        assert a.getGrade() == 1
        assert a.getID() == "1"
        try: 
            a = Assignment("","hello","world",0,1)
            a = Assignment("1","hi","wor",0,1)
            assert 1 == 0
        except:
            pass
        
    def testLinkClass(self):
        a = Assignment("1","hello","world",1,1)
        b = Student("3","Picks",50)
        newlinkid = 3
        c = Link(b,a,newlinkid)
        assert c.getStud().getID() == '3'
        assert c.getAssign().getKeyID() == 1
        assert c.getID() == 3
                
    def testAssignRepo(self):
        a = AssignRepo()
        b = Assignment("1","Heir of Breath","19/04/2009",1,1)
        c = Assignment("2","Knight of Time","19/04/2009",1,2)
        d = Assignment("3","Seer of Light","19/04/2009",1,3)
        e = Assignment("3","Witch of Space","19/04/2009",1,4)
        a.add(b)
        assert len(a) == 1
        a.add(c)
        assert len(a) == 2
        a.add(d)
        a.add(e)
        a.removeById(c.getKeyID())
        assert len(a) == 3
    
        
if __name__ == '__main__':
    unittest.main()      
#testLinkRepo()
#testAssignRepo()
#testStudentClass() 
#testAssignClass()
#testStudentRepo()
#print("AssignRepoTest:")
#testAssignRepo()
     
