'''
Created on 29 Feb 2016

@author: Mihai
'''

class Controller(object):
    '''
    classdocs
    '''


    def __init__(self, repo):
        '''
        Constructor
        '''
        self._repo = repo
    
    def addEdge(self, startingVertex, destinationVertex, cost):
        self._repo.addEdge(startingVertex, destinationVertex, cost)
        
    def removeEdge(self, startingVertex, destinationVertex):
        self._repo.removeEdge(startingVertex, destinationVertex)
        
    def isEdge(self,sourceVertex, destinationVertex):
        return self._repo.isEdge(sourceVertex, destinationVertex)
    
    def parseNout(self, vertex):
        return self._repo.parseNout(vertex)
    
    def parseNin(self, vertex):
        return self._repo.parseNin(vertex)
        
    def getAllVertices(self):
        return self._repo.getAllVertices()
    
    def removeVertex(self, vertex):
        self._repo.removeVertex(vertex)
        
    def addVertex(self, vertex):
        return self._repo.addVertex(vertex)
    
    def accessible(self, sourceVertex):
        return self._repo.accessible(sourceVertex)
    
    def connectedComponents(self):
        '''
        Returns a list containing lists of all connected components in a graph
        '''
        componentList = []
        usedVertices = []
        for counter in self._repo._graph.getAllVertices():
            if counter in usedVertices:
                    break
            accessibleFrom = self.accessible(counter)
            componentList.append(accessibleFrom)
            for counter2 in accessibleFrom:
                usedVertices.append(counter2)
                
        return componentList
                
            
        
    