from random import randint
from domain.AssignClass import Assignment
from copy import deepcopy

def filter(list,value,*,key = None):
    '''
    filters numbers by a given value (greater than the given value)
    list - list of numbers to be filtered
    key - key by which the numbers are filtered
    '''
    newlist = []
    if key == None:
        key = lambda i: i
    for ct in range (0,len (list)):
        if key(ct) >  value:
            newlist.append(list[ct])
            print(list[ct])
    return newlist
       

def Combsort(list,*,key = None,reverse = False):
    '''
    list - the list of elements to be sorted
    key - the key by which the elements are sorted
    reverse - chooses if the sort is ascending or descending
    gap - variable used for combsort, that specifies the elements to be compared
    '''
    if key == None:
        key = lambda i: i
    gap = int(len(list)/2) 
    shrink = 1.3
    swapped = True
    while gap >= 1 and swapped == True:
        gap = int(gap/shrink)
        if gap < 1:
            gap = 1
        ct = 0
        swapped = False
        while ct + gap < len(list):
            if key(list[ct]) > key(list[ct + gap])and reverse == False:                
                auxiliar = list[ct]
                list[ct] = list[ct + gap]
                list[ct + gap] = auxiliar
                swapped = True
            elif key(list[ct]) < key(list[ct + gap]) and reverse == True:                
                auxiliar = list[ct]
                list[ct] = list[ct + gap]
                list[ct + gap] = auxiliar
                swapped = True
            ct += 1
            
    return list      
      
      
def testCombsort():
    for counter in range (0,100):
        list = []
        for counter2 in range (0,100):
            list.append(randint(-10000,10000))
        assert sorted(list)==Combsort(list)

def testFilter():
    list = []
    for counter2 in range (0,100):
            list.append(randint(-10000,10000))
    value = 5000
    newlist = deepcopy(filter(list,value))
    for ct in newlist:
        assert ct > 5000 == True

testCombsort()
testFilter() 
print("It worked!")