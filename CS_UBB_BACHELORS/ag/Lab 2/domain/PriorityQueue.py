'''
Created on 21 May 2016

@author: Mihai
'''


class PriorityQueue(object):
    '''
    classdocs
    '''


    def __init__(self):
        '''
        Constructor
        Key is the element, value is the priority
        '''

        self.elements={};
        
    def append(self,key,priority):
        self.elements[key] = priority
        
    def pop(self):
        if len(self.elements) == 0:
            return None
        #min = self.elements[self.elements.keys()[0]]
        mink = self.elements.keys()[0]
        for ct in self.elements.keys():
            if self.elements[ct] < min:
                #min = self.elements[ct]
                mink = ct
        return mink
    