'''
Created on 29 Feb 2016

@author: Mihai
'''
from domain.DoubleDirectedGraph import Graph
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
        
        for counter in range(0,len(self._graph._dictOut[startingVertex])):
            if self._graph._dictOut[startingVertex][counter] == destinationVertex:
                
                self._graph._dictOut[startingVertex].pop(counter)
                break
        for counter in range(0,len(self._graph._dictIn[destinationVertex])):
            if self._graph._dictIn[destinationVertex][counter] == startingVertex:
                self._graph._dictIn[destinationVertex].pop(counter)
                break
        
    def removeVertex(self, vertex):
        '''
        removes a vertex from the graph
        '''
        for counter in range(1, self._graph.getNrVertices()):
            self.removeEdge(vertex, counter)
            self._graph.removeCost(vertex, counter)
            self.removeEdge(counter, vertex)
            self._graph.removeCost(counter, vertex)
        
        self._graph._dictIn.pop(vertex)
        self._graph._dictOut.pop(vertex)
        self._graph.setNrVertices(self._graph.getNrVertices() - 1)
        
    def addVertex(self, vertex):
        setOfKeys = self._graph._dictOut.keys();
        if(vertex in setOfKeys):
            return False
        self._graph._dictIn[vertex] = []
        self._graph._dictOut[vertex] = []
        return True
    
    def accessible(self, sourceVertex):
        return self._graph.accessible(self._graph, sourceVertex)
                  
    def loadFromFile(self):
        print("wut?")
        file = open("data.txt","r")
        newline = file.readline()
        newline = newline.split(" ")
        #nrOfVertices = int(newline[0])
        nrOfEdges = int(newline[1])
        for _ in range(0, nrOfEdges):
            newLine = file.readline()
            newLine = newLine.split(" ")
            print(newLine)
            self.addEdge(int(newLine[0]), int(newLine[1]), int(newLine[2]))
        
            
            
    def saveToFile(self):
        file = open("data.txt","w")
        self.saveToAFile(file)
     
    
    def saveToAFile(self, file):  
        nrEdges = 0
        for counter in self._graph._dictOut:
            nrEdges += len(self._graph._dictOut[counter])
        file.write(str(len(self.getAllVertices())) + " " + str(nrEdges) + "\n")
        for counter in self._graph._dictOut:
            for counter2 in self._graph._dictOut[counter]:
                file.write(str(counter) + " " + str(counter2) + " " + str(self._graph._dictCosts[(counter,counter2)]) + "\n")
    
#---------------------TAKEN FROM DOMAIN---------------------       
        
    def addEdge(self, startingVertex, destinationVertex, cost):
        self._graph.addEdge(startingVertex, destinationVertex, cost)
        
    def isEdge(self,sourceVertex, destinationVertex):
        return self._graph.isEdge(sourceVertex, destinationVertex)
    
    def parseNout(self, vertex):
        return self._graph.parseNout(vertex)
    
    def parseNin(self, vertex):
        return self._graph.parseNin(vertex)
        
    def getAllVertices(self):
        return self._graph.getAllVertices()
    
    
#---------------------TAKEN FROM DOMAIN---------------------  
