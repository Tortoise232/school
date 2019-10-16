'''
Created on 29 Feb 2016

@author: Mihai
'''
from domain.UndirectedGraph import Graph
class Repository(object):
    '''
    serves as repository for the graph
    '''


    def __init__(self, graph):
        '''
        initiates the graph
        '''
        self._graph = graph

    def removeEdge(self, startingVertex, destinationVertex):
        '''
        removes an edge from the dictOut and dictIn
        '''
        
        try:
            self._graph._dict[startingVertex].remove(destinationVertex)
        
        except:
            pass
        try:
            self._graph._dict[destinationVertex].remove(startingVertex)
        except:
            pass
        
    def removeVertex(self, vertex):
        '''
        removes a vertex from the graph
        '''    
        for counter in self._graph._dict.keys():
            try:
                self._graph._dict[counter].remove(vertex)
            except:
                pass
        self._graph._dict.pop(vertex)
        self._graph.setNrVertices(self._graph.getNrVertices() - 1)
        
    def addVertex(self, vertex):
        '''
        Adds a new vertex to the graph
        '''
        setOfKeys = self._graph._dict.keys();
        if(vertex in setOfKeys):
            return False
        self._graph._dict[vertex] = []
        return True
    
    def accessible(self, sourceVertex):
        '''
        Returns a list of vertices accesible from a given vertex in the contained graph
        '''
        return self._graph.accessible(self._graph, sourceVertex)
                  
    def loadFromFile(self):
        file = open("data.txt","r")
        newline = file.readline()
        newline = newline.split(" ")
        nrOfEdges = int(newline[0])
        for _ in range(0, nrOfEdges):
            newLine = file.readline()
            newLine = newLine.split(" ")
            if(len(newLine) == 1):
                
                self._graph._dict[int(newLine[0])] = {}
                return 0
            if int(newLine[0]) not in self._graph._dict.keys():
                self._graph._dict[int(newLine[0])] = []
            if int(newLine[1]) not in self._graph._dict.keys():
                self._graph._dict[int(newLine[1])] = []
            #print(newLine)
            self.addEdge(int(newLine[0]), int(newLine[1]))
            
    def connectedComponents(self):
        '''
        Returns a list containing lists of all connected components in a graph
        '''
        componentList = []
        usedVertices = []
        for counter in self._graph.getAllVertices():
            if counter not in usedVertices:       
                accessibleFrom = self.accessible(counter)
                componentList.append(accessibleFrom)
                for counter2 in accessibleFrom:
                    usedVertices.append(counter2)       
        return componentList 

    
#---------------------TAKEN FROM DOMAIN---------------------       
        
    def addEdge(self, startingVertex, destinationVertex):
        self._graph.addEdge(startingVertex, destinationVertex)
        
    def isEdge(self,sourceVertex, destinationVertex):
        return self._graph.isEdge(sourceVertex, destinationVertex)
    
    def parse(self, vertex):
        return self._graph.parse(vertex)
        
    def getAllVertices(self):
        return self._graph.getAllVertices()
    
    
#---------------------TAKEN FROM DOMAIN---------------------  
