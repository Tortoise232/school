'''
Created on 5 Mar 2016

@author: Mihai
'''
from copy import deepcopy
class UI(object):
    '''
    represents the interface with which the user interacts
    '''


    def __init__(self, controller):
        '''
        Constructor
        '''
        self._controller = controller
        
    
        
    
    def showVertices(self):
        '''
        Shows all vertices in the graph
        '''
        print(self._controller.getAllVertices())
     
    def showNumberVertices(self):
        '''
        shows how many vertices there are in the graph
        '''
        print("The number of vertices is:",len(self._controller.getAllVertices()))
        
    def displayDegree(self):
        print("Input vertex: ")
        vertex = int(input())
        print("Degree:",len(self._controller.parse(vertex)))
        
    def displayEdgeFromVertex(self):
        '''
        Displays all edges having the starting point the input vertex
        '''
        print("Input starting vertex: ")
        startingVertex = int(input())
        print(self._controller.parse(startingVertex))
        
    def addEdge(self):
        '''
        Adds an edge to the graph, by asking for starting and destination vertices
        '''
        print("Input starting vertex: ")
        startingVertex = int(input())
        print("Input destination vertex: ")
        destinationVertex = int(input())
        self._controller.addEdge(startingVertex, destinationVertex)
        
    def removeEdge(self):
        '''
        Removes an edge from the graph, by asking for starting and destination vertices
        '''
        print("Input starting vertex: ")
        startingVertex = int(input())
        print("Input destination vertex: ")
        destinationVertex = int(input())
        self._controller.removeEdge(startingVertex, destinationVertex)
     
    def removeVertex(self):
        '''
        Removes a vertex by removing all edges coming from and to the given vertex
        '''
        print("IF YOU DELETE ANY VERTEX OTHER THAN THE LAST VERTEX IN THE GRAPH THE SAVED DATA WILL BE INCORRECT!\n\n")
        print("Input vertex for deletion: ")
        vertex = int(input())
        self._controller.removeVertex(vertex)
        
    
    def addVertex(self):
        print("IF YOU ADD ANY VERTEX OTHER THAN THE ONE THAT FOLLOWS THE LAST VERTEX IN THE GRAPH THE SAVED DATA WILL BE INCORRECT!\n\n")
        print("Input vertex for adding:")
        vertex = int(input())
        if self._controller.addVertex(vertex) == False:
            print("Vertex is already in the graph!")
            
            
        
    def isEdge(self):
        print("Input starting vertex: ")
        startVertex = int(input())
        print("Input destination vertex: ")
        destinationVertex = int(input())
        if(self._controller.isEdge(startVertex, destinationVertex)):
            print("Edge found starting from vertex",startVertex,"to vertex",destinationVertex)
        else:
            print("No edge found!")
    
    def makeACopy(self):
        self._controller._repo._graph._copyOfGraph = deepcopy(self)
        
    def accessible(self):
        print("Input vertex: ")
        startVertex = int(input())
        listOfAccessible = self._controller.accessible(startVertex)
        print(listOfAccessible)
        
    def connected(self):
        print("Connected components of the graph are: ")
        print(self._controller.connectedComponents())
        
    def biconnected(self):
        if self._controller.biconnectedGraph() == True:
            print("Graph is indeed biconnected!")
        else:
            print("Graph is not biconnected!")
   
    def showOpt(self):
        print("1.Get number of vertices")
        print("2.Is edge between two vertices (and print cost)")
        print("3.Display degree of a vertex")
        print("4.Display edges from a vertex")
        print("5.Add edge")
        print("6.Remove edge")
        print("7.Remove vertex")
        print("8.Add vertex")
        print("9.Make a copy of the graph")
        print("10.List vertices accessible from a given vertex")
        print("11.Connected components")
        print("12.Test is graph is biconnected")
        print("0.Exit")
        
    def mainLoop(self):
        '''
        main loop of the U.I.
        '''
        while True:
            try:
                self.showOpt()
                option = input()
                if option == '1':
                    self.showNumberVertices()
                    print(self._controller.getAllVertices())
                elif option == '2':
                    self.isEdge()
                elif option == '3':
                    self.displayDegree()
                elif option == '4':
                    self.displayEdgeFromVertex()
                elif option == '5':
                    self.addEdge()
                elif option == '6':
                    self.removeEdge()
                elif option == '7':
                    self.removeVertex()
                elif option =='8':
                    self.addVertex()
                elif option == '9':
                    self.makeACopy()
                elif option == '10':
                    self.accessible()
                elif option =='11':
                    self.connected()
                elif option =='12':
                    self.biconnected()
                elif option == '0':
                    break
            except KeyError as e:
                print("Invalid input! One of the following vertices is invalid:", e)
                    