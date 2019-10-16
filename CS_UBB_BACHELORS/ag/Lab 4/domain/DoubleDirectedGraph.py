'''
Created on 29 Feb 2016

@author: Mihai
'''
from copy import deepcopy

class Graph(object):
    '''
    represents the graph object
    '''


    def __init__(self, nr_of_vertices):
        '''
        Creates two dictionaries representing the successors and predecessors of each vertex
        input: nr_of_vertices - integer number that represents the number (and id) of vertices that the graph has to be created upon
        '''
        self._copyOfGraph = None
        self._dictOut = {}
        self._dictIn = {}
        for counter in range(0, nr_of_vertices):
            self._dictOut[counter] = []
            self._dictIn[counter] = []
        self._nrVertices = nr_of_vertices
        self._dictCosts = {}
    
    def removeCost(self,x,y):
        '''
        removes the cost associated to an edge
        '''
        try:
            self._dictCosts.pop((x,y))
        except:
            pass
    
    def getNrVertices(self):
        '''
        returns the number of vertices the graph has
        '''
        return self._nrVertices 
    
    def setNrVertices(self, newNumber):
        '''
        updates the number of vertices in the graph to new
        '''
        self._nrVertices = newNumber
        
          
    def getAllVertices(self):
        '''
        returns a list of all vertices
        '''
        setOfKeys = self._dictOut.keys();
        newList = []
        for counter in setOfKeys:
            newList.append(counter)
        return newList            
    
    def parseNout(self, vert):
        '''
        returns all the successors of the vertex vert
        '''
        return self._dictOut[vert]
    
    def parseNin(self, vert):
        '''
        returns all the predecessors of the vertex vert
        '''
        return self._dictIn[vert];
    
    def isEdge(self, sourceVertex, destinationVertex):
        '''
        returns true if there is an edge from the source vertex to the destination vertex and 0 otherwise
        '''
        try:
            if destinationVertex in self._dictOut[sourceVertex]:
                return self._dictCosts[(sourceVertex, destinationVertex)]
            else:
                return None
        except:
            print("Invalid vertex(vertices)!")
    
    def addEdge(self, sourceVertex, destinationVertex, cost):
        '''
        adds an edge from the destination to the source
        '''
        self._dictOut[sourceVertex].append(destinationVertex)
        self._dictIn[destinationVertex].append(sourceVertex)
        self._dictCosts[(sourceVertex, destinationVertex)] = cost
        #print(self._dictCosts[(sourceVertex, destinationVertex)] )
     
    def getAllEdges(self):
        list = self._dictCosts.keys()
        return list
       
    def accessible(self, graph, sourceVertex):
        '''
        shows all the vertices that are accessible from the sourceVertex in the graph
        '''
        accessible = set()
        accessible.add(sourceVertex)
        listOfAccVert = [sourceVertex]
        while len(listOfAccVert) > 0:
            x = listOfAccVert[0]
            listOfAccVert = listOfAccVert[1: ]
            for y in graph.parseNout(x):
                if y not in accessible:
                    accessible.add(y)
                    listOfAccVert.append(y)
        return accessible
    
    
        
    