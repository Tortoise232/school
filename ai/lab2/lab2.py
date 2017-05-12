#MAD PYTHON CODE:
from copy import deepcopy


class Excavator:
    def __init__(self,consumptions, id):
        self.consumptions = consumptions
        self.id = id

    def getConsumption(self, siteID):
        return self.consumptions[siteID]

    def getID(self):
        return self.id

    def __eq__(self, other):
        return self.getID() == other.getID()

    def __str__(self):
        myString = str(self.getID) + " : "
        for cons in self.consumptions:
            myString += str(cons) + ", "

        return myString

class State:
    def __init__(self,excavators):
        self.excavators = excavators
        self.nExcavators = len(self.excavators)
        self.sortedExcavators = []
        self.fitness = 0

    def getFitness(self):
        self.fitness = 0
        for site in range(0, len(self.sortedExcavators)):
            self.fitness += self.sortedExcavators[site].getConsumption(site)
        return self.fitness

    def validate(self):
        if len(self.sortedExcavators) == self.nExcavators:
            return True
        return False

    def __str__(self):
        self.getFitness()
        myString = ""
        myString += "order: "
        for sortedEx in self.sortedExcavators:
            myString += str(sortedEx.getID()) + " "

        myString += "fitness: " + str(self.fitness)
        return myString

    def __lt__(self,other):
        return self.getFitness() < other.getFitness()


class Problem:
    def __init__(self, filename):
        self.initialState = []
        self.finalState = []
        self.readFromFile(filename)

    def readFromFile(self, filename):
        excavators = []
        try:
            file = open(filename, 'r')
        except IOError:
            return
        n = file.readline()
        n = int(n)
        for counter in range(0, n):
            excavator = file.readline()
            excavator = excavator.split(" ")
            excavator.pop()
            values = []
            for consumption in excavator:
                values.append(int(consumption))
            excavators.append(Excavator(values,counter))

        self.initialState = State(excavators)
        file.close()

    #expand the states
    def expand(self,state):
        listOfStates = []
        for excavator in state.excavators:
            #create a new state
            newState = deepcopy(state)
            newState.sortedExcavators.append(excavator)
            newState.excavators.remove(excavator)
            #assign it to list of states
            listOfStates.append(newState)
        return listOfStates



class Controller:
    def __init__(self,problem):
        self.problem = problem

    def dfs(self,problem,solutions):
        while len(solutions) != 0:
            state = solutions.pop()
            expandedSolutions = problem.expand(state)
            self.dfs(problem,expandedSolutions)
            if state.validate():
                if self.problem.finalState:
                    if self.problem.finalState > state:
                        self.problem.finalState = state
                else:
                    self.problem.finalState = state
                print(state)


    def gbfs(self,problem,solutions):
        while len(solutions) > 0:
            solutions.sort()
            state = solutions.pop(0)
            expandedSolutions = problem.expand(state)
            self.gbfs(problem,expandedSolutions)
            if state.validate():
                if self.problem.finalState:
                    if self.problem.finalState > state:
                        self.problem.finalState = state
                else:
                    self.problem.finalState = state
                print(state)


class UI:
    def __init__(self):
        self.controller = Controller(Problem("data.txt"))

    def showOptions(self):
        print("1) DFS")
        print("2) GBFS")

    def mainLoop(self):
        self.showOptions()
        choice = input()
        if choice == '1':
           self.controller.dfs(self.controller.problem, self.controller.problem.expand(self.controller.problem.initialState))
        if choice == '2':
            self.controller.gbfs(self.controller.problem,
                                self.controller.problem.expand(self.controller.problem.initialState))
        print("FINAL SOLUTION:")
        print(str(self.controller.problem.finalState))
        end = input()

myUI = UI()
myUI.mainLoop()
