'''
Created on 29 Feb 2016

@author: Mihai
'''
from domain.UndirectedGraph import Graph
from Repository.Repository import Repository
from copy import deepcopy
from domain.PriorityQueue import PriorityQueue
class Controller(object):
    '''
    classdocs
    '''


    def __init__(self, repo):
        '''
        Constructor
        '''
        self._repo = repo
    
    def addEdge(self, startingVertex, destinationVertex,):
        self._repo.addEdge(startingVertex, destinationVertex)
        
    def removeEdge(self, startingVertex, destinationVertex):
        self._repo.removeEdge(startingVertex, destinationVertex)
        
    def isEdge(self,sourceVertex, destinationVertex):
        return self._repo.isEdge(sourceVertex, destinationVertex)
    
    def parse(self, vertex):
        return self._repo.parse(vertex)
        
    def getAllVertices(self):
        return self._repo.getAllVertices()
    
    def removeVertex(self, vertex):
        self._repo.removeVertex(vertex)
        
    def addVertex(self, vertex):
        return self._repo.addVertex(vertex)
    
    def accessible(self, sourceVertex):
        return self._repo.accessible(sourceVertex)
    
    def connectedComponents(self):
        return self._repo.connectedComponents()
                
    def biconnectedComponent(self, listOfVertices):
        newGraph = Graph()
        for counter in listOfVertices:#copies dictionary of edges
            newGraph._dict[counter] = self._repo._graph._dict[counter]
            newGraph._nrVertices = len(listOfVertices)
        
        checkForBiconnected = True
        for counter in listOfVertices:
            newGraph2 = Graph()
            newGraph2._dict = deepcopy(newGraph._dict)
            newGraph2._nrVertices = deepcopy(newGraph._nrVertices)
            newRepo = Repository(newGraph2)
            newRepo.removeVertex(counter)
            if (len(newRepo.connectedComponents())  != 1):
                checkForBiconnected = False
        if checkForBiconnected == True:
            return True
        else:
            return False
                
    def biconnectedGraph(self):
        listOfComponents = self.connectedComponents()
        checkForBiconnected = True
        for counter in listOfComponents:
            if(len(counter) > 1):
                checkForBiconnected = self.biconnectedComponent(counter)
            #else: 
                #return False   
        return checkForBiconnected


        
        
        
        
        