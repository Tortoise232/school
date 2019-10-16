'''
Created on 29 Feb 2016

@author: Mihai
'''


class Graph(object):
    '''
    represents the graph object
    '''


    def __init__(self):
        '''
        Creates two dictionaries representing the successors and predecessors of each vertex
        input: nr_of_vertices - integer number that represents the number (and id) of vertices that the graph has to be created upon
        '''
        self._copyOfGraph = None
        self._dict = {}
        self._nrVertices = 0
    
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
        setOfKeys = self._dict.keys();
        newList = []
        for counter in setOfKeys:
            newList.append(counter)
        return newList            
    
    def parse(self, vert):
        '''
        returns all the successors of the vertex vert
        '''
        listOfVertices = self._dict[vert]
        for counter in self.getAllVertices():
            if vert in self._dict[counter] and counter not in listOfVertices:
                listOfVertices.append(counter)
        return listOfVertices             
    
    def isEdge(self, sourceVertex, destinationVertex):
        '''
        returns true if there is an edge from the source vertex to the destination vertex and 0 otherwise
        '''          
        if (sourceVertex in self._dict[destinationVertex]) or (destinationVertex in self._dict[sourceVertex]):
            return True 
        
    def addEdge(self, sourceVertex, destinationVertex):
        '''
        adds an edge from the destination to the source
        '''
        #if destinationVertex not in self._dict[sourceVertex]:
        self._dict[sourceVertex].append(destinationVertex)
        self._dict[destinationVertex].append(sourceVertex)
        
    def accessible(self, graph, sourceVertex):
        '''
        shows all the vertices that are accessible from the sourceVertex in the graph
        '''
        accessible = set()
        accessible.add(sourceVertex)
        listOfAccVert = [sourceVertex]
        listOfEdges = {}
        '''
        #This is BFS
        while len(listOfAccVert) > 0: 
            x = listOfAccVert[0]
            listOfAccVert = listOfAccVert[1: ]
            for y in graph.parse(x):
                if y not in accessible:
                    accessible.add(y)
                    listOfAccVert.append(y)
        return accessible
        '''
        self.dfs(sourceVertex, accessible, graph, listOfAccVert, listOfEdges)
        #print(listOfEdges)
        return accessible
    
    def dfs(self, vertex, accesible, graph, listOfAccVert, listOfEdges):
        '''
        recursive depth first search
        '''
        listOfEdges[vertex] = []
        for neighbour in graph.parse(vertex):    
            if neighbour not in accesible :
                accesible.add(neighbour)
                listOfAccVert.append(neighbour)
                if(neighbour not in listOfEdges[vertex]):
                    listOfEdges[vertex].append(neighbour)
                self.dfs(neighbour, accesible, graph, listOfAccVert, listOfEdges)
        
    