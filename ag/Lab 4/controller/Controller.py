'''
Created on 29 Feb 2016

@author: Mihai
'''
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
    
    def getAllEdges(self):
        return self._repo.getAllEdges()
    
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
                
    def dijsktra(self,nodeA,nodeB):
        #works
        queue = PriorityQueue()
        previous = {}
        distance = {}
        distance[nodeA] = 0
        queue.append(nodeA,0)
        found = False
        while not found and len(queue.elements)!=0 :
            x = queue.pop()
            for y in self.parseNout(x):
                if y not in distance or distance[x] + self._repo._graph._dictCosts[(x, y)] < distance[y] :     
                    distance[y] = distance[x] + self._repo._graph._dictCosts[(x, y)]
                    queue.append(y,distance[y])
                    previous[y] = x
            if y == nodeB:
                found = True
        
        toPrint = y
        results = []
        results.append(toPrint)
        print("Distance to ",y," is ", distance[y])
        while( toPrint in previous.keys()):
            results.append(previous[toPrint])
            toPrint = previous[toPrint]
        print(results)
        
    def minDist(self,nodeA,nodeB):
        #works
        previous = {}
        distance = {}
        change = True
        for x in self.getAllVertices():
            distance[x] = 9999
        distance[nodeA] = 0
        while change:
            change = False
            for key in self.getAllEdges():
                if distance[key[1]] > distance[key[0]] + self._repo._graph._dictCosts[(key[0], key[1])] or distance[key[1]] == 9999:
                    x = key[0]
                    y = key[1]
                    distance[y] = distance[x] + self._repo._graph._dictCosts[(x, y)]
                    previous[y] = x
                    change = True
        return(distance[nodeB])  
    
    def maxDist(self,nodeA,nodeB): 
        previous = {}
        distance = {}
        distance[nodeB] = 9999
        
        change = True
        for x in self.getAllVertices():
            distance[x] = 9999
        distance[nodeA] = 0
        while change:
            change = False
            for key in self.getAllEdges():
                if (distance[key[1]] < distance[key[0]] + self._repo._graph._dictCosts[(key[0], key[1])] and distance[key[0]] != 9999) or ( distance[key[1]] == 9999 and distance[key[0]] != 9999):
                    x = key[0]
                    y = key[1]
                    distance[y] = distance[x] + self._repo._graph._dictCosts[(x, y)]
                    previous[y] = x
                    change = True
        return(distance[nodeB])  
         
    '''
    Sorts the given graph on levels, using predecessor count
    '''   
    def topoSortPredCount(self):
         
        verticesNoutCounter= {}
        sortedVertices = {}
        toBeErased = set()
        levelOfVertice = 0
        safetyCheck = 999
        for counter in self.getAllVertices():
            verticesNoutCounter[counter] = len(self.parseNin(counter))
        while(len(sortedVertices) != len(self.getAllVertices()) and safetyCheck > 0):
            keys = verticesNoutCounter.keys()
            for counter in keys:
                if(verticesNoutCounter[counter] == 0):
                    toBeErased.add(counter)
            for vertices in toBeErased:
                    for affectedVertices in self.parseNout(vertices):
                        verticesNoutCounter[affectedVertices] -= 1
                    sortedVertices[vertices] = levelOfVertice
                    verticesNoutCounter.pop(vertices)
            toBeErased.clear()
            levelOfVertice += 1
            safetyCheck -= 1    
        if(safetyCheck == 0):
            return None    
        else: 
            return sortedVertices
            
    def earliestStart(self,sortedByLevel,node):
        if(sortedByLevel[node] == 0):
            return 0;
        startingVertices = []
        for vertex in sortedByLevel.keys():
            if(sortedByLevel[vertex] == 0):
                startingVertices.append(vertex)
        minDist = 9999999
        for counter in startingVertices:
            if(self.minDist(counter, node) < minDist):
                minDist = self.minDist(counter, node)
        return minDist
    
    def latestStartLevel0(self,sortedByLevel,node):
        levelOne = []
        maxDist = 0
        for vertex in sortedByLevel.keys():
            if(sortedByLevel[vertex] == 1):
                if(maxDist < self.latestStart(sortedByLevel,vertex)):
                    maxDist = self.latestStart(sortedByLevel, vertex)
        maxDist -= self.isEdge(node,self.parseNout(node)[0])
        return maxDist
    
    def latestStart(self,sortedByLevel,node):
        if(sortedByLevel[node] == 0):
            return self.latestStartLevel0(sortedByLevel,node)
        startingVertices = []
        for vertex in sortedByLevel.keys():
            if(sortedByLevel[vertex] == 0):
                startingVertices.append(vertex)
        maxDist = 0
        for counter in startingVertices:
            if(self.minDist(counter, node) > maxDist):
                maxDist = self.maxDist(counter, node)
        return maxDist
    
    def DFSRec(self,nodeA,nodeB,visitedVertices, vertices, globalMax,valueSoFar, globalList):
        if(nodeA == nodeB):
            if(valueSoFar > globalMax):
                globalMax = valueSoFar
                globalList = vertices
                return vertices
        for counter in self.parseNout(nodeA):
            vertices.append(counter)
            valueSoFar += self.isEdge(nodeA,counter)
            vertices = self.DFSRec(counter,nodeB,visitedVertices,vertices,globalMax, valueSoFar, globalList)
            
    
    def maxPathDFS(self,nodeA,nodeB):
        visitedVertices = []
        vertices = []
        globalList = []
        globalMax = 0
        self.DFSRec(nodeA,nodeB,visitedVertices, vertices, globalMax, 0, globalList)
        result = []
        result.append(globalMax)
        result.append(globalList)
        return result
    
    def activityTimes(self):
        toposortedVertices = self.topoSortPredCount()
        for vertex in toposortedVertices:
            print("Vertex: ",vertex," Earliest time: ",self.earliestStart(toposortedVertices, vertex)," Latest time: ",self.latestStart(toposortedVertices, vertex))
    
    def criticalPath(self):
        return
        maxPathDist = 0
        maxList = []
        for counter in self.getAllVertices():
            for counter2 in self.getAllVertices():
                if self.maxPathDFS(counter, counter2)[0] > maxPathDist and self.maxPathDFS(counter, counter2)[1] < 9999:
                    maxList = self.maxPathDFS(counter,counter2)[1]
        return maxList
                                                                                                
        
        