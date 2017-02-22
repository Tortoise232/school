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
        
    def showOpt(self):
        print("1.Get number of vertices")
        print("2.Is edge between two vertices (and print cost)")
        print("3.Display the in and out  degree of a vertex")
        print("4.Display outbound edges?")
        print("5.Display inbound edges?")
        print("6.Add edge")
        print("7.Remove edge")
        print("9.Remove vertex")
        print("10.Add vertex")
        print("11.Modify edge cost")
        print("12.Make a copy of the graph")
        print("13.List vertices accessible from a given vertex")
        print("0.Exit")
        
    
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
        print("Out degree:",len(self._controller.parseNout(vertex)))
        print("In degree:",len(self._controller.parseNin(vertex))) 
        
    def displayEdgeFromVertex(self):
        '''
        Displays all edges having the starting point the input vertex
        '''
        print("Input starting vertex: ")
        startingVertex = int(input())
        print(self._controller.parseNout(startingVertex))
        
    def displayEdgeToVertex(self):
        '''
        Displays all edges having the destination point the input vertex
        '''
        print("Input destination vertex: ")
        destinationVertex = int(input())
        print(self._controller.parseNin(destinationVertex))
        
    def addEdge(self):
        '''
        Adds an edge to the graph, by asking for starting and destination vertices
        '''
        print("Input starting vertex: ")
        startingVertex = int(input())
        print("Input destination vertex: ")
        destinationVertex = int(input())
        print("Input edge cost: ")
        edgeCost = int(input())
        self._controller.addEdge(startingVertex, destinationVertex, edgeCost)
        
    def removeEdge(self):
        '''
        Removes an edge from the graph, by asking for starting and destination vertices
        '''
        print("Input starting vertex: ")
        startingVertex = int(input())
        print("Input destination vertex: ")
        destinationVertex = int(input())
        self._controller._repo._graph._dictCosts.pop((startingVertex, destinationVertex))
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
            
    def modifyEdgeInfo(self):
        print("Input starting vertex of the edge: ")    
        startingVertex = int(input())
        print("Input destination vertex of the edge: ")
        destinationVertex = int(input())
        if(self._controller.isEdge(startingVertex, destinationVertex)):
            print("Cost of edge:",self._controller._repo._graph._dictCosts[(startingVertex, destinationVertex)])
        else:
            print("No edge found!")
            return 0
        print("Input new cost to modify cost \nInput x to leave value unchanged")
        value = input()
        if value == 'x':
            return 0
        else:
            self._controller.addEdge(startingVertex, destinationVertex, int(value))
            
        
    def isEdge(self):
        print("Input starting vertex: ")
        startVertex = int(input())
        print("Input destination vertex: ")
        destinationVertex = int(input())
        if(self._controller.isEdge(startVertex, destinationVertex)):
            print("Edge found starting from vertex",startVertex,"to vertex",destinationVertex)
            print("Cost of edge:",self._controller._repo._graph._dictCosts[(startVertex, destinationVertex)])
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
                elif option == '2':
                    self.isEdge()
                elif option == '3':
                    self.displayDegree()
                elif option == '4':
                    self.displayEdgeFromVertex()
                elif option == '5':
                    self.displayEdgeToVertex()
                elif option == '6':
                    self.addEdge()
                elif option == '7':
                    self.removeEdge()
                elif option == '9':
                    self.removeVertex()
                elif option =='10':
                    self.addVertex()
                elif option == '11':
                    self.modifyEdgeInfo()
                elif option == '12':
                    self.makeACopy()
                elif option == '13':
                    self.accessible()
                elif option =='14':
                    self.connected()
                elif option == '0':
                    break
            except KeyError as e:
                print("Invalid input! One of the following vertices is invalid:", e)
                    