#MAD PYTHON CODE:
from copy import deepcopy
from random import shuffle
import random
#example encoding
#      W O R D
#      # R # I
#      # # # S
#      # A S H
#
# list of words: word or ash dish
# marker = 2 (word[0] and word[1] will be horizontal and word[2] and word[3] vertical)
# take all words in order, genome is this order in the individual (ex: 1 3 2 4 = word ash or dish);
# try and assemble the board, check for mismatches, establish fitness, retry


#genotype - order of words
#listOfWords - self-explanatory
class Individual:

    def createBoard(self):
        filledBoard = self.board.copy()
        listOfSpacesCt = 0

        #horizontal words
        for ct in (self.genotype):
            if(listOfSpacesCt == self.splitMark):
                break
            space = self.listOfSpaces[listOfSpacesCt]
            initialX = space[1][1]
            initialY = space[1][0]
            word = self.listOfWords[ct]
            #how many letters we will fill = n
            n = len(word)
            #if the word is going across the borders - fitness tax
            if initialX + len(word) > len(self.board):
                self.fitness +=  (initialX + len(word) - len(self.board)) * self.penaltyQuantifier
                n -=  initialX + len(word) - len(self.board)
            for letterNr in range(0,n):
                #if a letter is on a black space
                if self.board[initialY][initialX + letterNr] == '1' :
                    self.fitness +=  (n - letterNr)
                    break
                else:
                    # if the letter does not match
                    if self.board[initialY][initialX + letterNr] != '0' and self.board[initialY ][initialX + letterNr] != word[letterNr]:
                        self.fitness += 1
                        self.board[initialY][initialX + letterNr] = word[letterNr]
                    #the letter occupies a valid space
                    else:
                        self.board[initialY][initialX + letterNr] = word[letterNr]
            listOfSpacesCt += 1

        #vertical words
        for ct2 in range(listOfSpacesCt, len(self.listOfWords)):
            ct = self.genotype[ct2]
            space = self.listOfSpaces[listOfSpacesCt]
            initialX = space[1][1]
            initialY = space[1][0]
            word = self.listOfWords[ct]
            # how many letters we will fill = n
            n = len(word)
            # if the word is going across the borders - fitness tax
            if initialY + len(word) > len(self.board):
                self.fitness += (initialY + len(word) - len(self.board)) * self.penaltyQuantifier
                n -= initialY + len(word) - len(self.board)
            for letterNr in range(0, n):
                # if a letter is on a black space
                if self.board[initialY  + letterNr][initialX] == '1':
                    self.fitness += (n - letterNr)
                    break
                else:
                    # if the letter does not match
                    if self.board[initialY + letterNr][initialX] != '0' and self.board[initialY + letterNr][initialX] != word[letterNr]:
                        self.fitness += 1
                    # the letter occupies a valid space
                    else:
                        self.board[initialY + letterNr][initialX ] = word[letterNr]
            listOfSpacesCt += 1

        for ct1 in range(0,len(self.board)):
            for ct2 in range(0,len(self.board[0])):
                if self.board[ct1][ct2] == '0':
                    self.fitness += self.penaltyQuantifier

    def mutate(self,probability):
        for ct in range(0,len(self.genotype)):
            if random.uniform(0, 1) < probability:
                positionToSwitch = random.randint(0,len(self.genotype) - 1)
                auxGene = self.genotype[ct]
                self.genotype[ct] = self.genotype[positionToSwitch]
                self.genotype[positionToSwitch] = auxGene

    #REFACTOR NAMES WHEN COMPLETELY SOBER
    def cycleCrossover(self, mom, probability):
        cycledGene = []
        selfChild = list(range(0,len(self.genotype)))
        otherChild = []
        for ct in range(0,len(self.genotype)):
            if random.uniform(0, 1) < probability:
                ogGene = self.genotype[ct]
                selfChild[ct] = ogGene
                cycledGene = mom.genotype[ct]
                while(str(ogGene) != str(cycledGene)):
                    for gene in range(0,len(self.genotype)):
                        if self.genotype[gene] == cycledGene:
                            cycledGeneCt = gene
                            selfChild[gene] = self.genotype[gene]
                            cycledGene = mom.genotype[gene]
                            #print(str(ogGene) + " " + str(cycledGene))
            break;
        for ct in range(0, len(self.genotype)):
            if selfChild[ct] != self.genotype[ct]:
                self.genotype[ct] = mom.genotype[ct]
        self.genotype = selfChild

    #that's how the child is made kek
    def crossover(self,mom,dad):
        for ct in range(0,len(mom.genotype)):
            if(random.randint(0,mom.fitness + dad.fitness) > mom.fitness):
                chosenGene = dad.genotype[ct]
            else:
                chosenGene = mom.genotype[ct]
            #find the gene
            for ct1 in range(0,len(self.genotype)):
                #put it in this place to ressemble the parent genotype
                if chosenGene == self.genotype[ct1]:
                    aux = self.genotype[ct]
                    self.genotype[ct] = chosenGene
                    self.genotype[ct1] = aux

    def evalFitness(self):
        self.fitness = 0
        self.createBoard()
        return self.fitness

    def __init__(self, listOfWords, genotype, board, listOfSpaces, splitMark):
        self.fitness = 0
        self.listOfWords = listOfWords
        #order of words
        self.penaltyQuantifier = 3
        self.genotype = deepcopy(genotype)
        self.board = deepcopy(board)
        self.listOfSpaces = listOfSpaces
        self.splitMark = splitMark

    def __str__(self):
        print("GENOTYPE: " + str(self.genotype))
        for line in self.board:
            string = ""
            for char in line:
                string += char
                string = string.replace('1', '*')

            print(string)
        print(">>>>>>>>>>>>>>>>>>")
        print(self.fitness)
        return ""


class Population:
    def __init__(self, individuals):
        self.listOfIndividuals = individuals

class Problem:
    #here we should have black spaces and word list

    def readParams(self,filename):
        try:
            file = open(filename, 'r')
        except IOError:
            print("FAILED READING THE FILE")
            return
        params = file.readline()
        params = params.split(' ')
        self.mutationFactor = float(params[0])
        self.crossoverFactor = float(params[1])
        self.populationSize = int(params[2])
        self.noGenerations = int(params[3])
        print("READ PARAMS SUCCESSFULLY")

    def readData(self, filename):
        try:
            file = open(filename, 'r')
        except IOError:
            print("FAILED READING THE FILE")
            return
        size = file.readline()
        size = size.split(" ")
        self.boardX = int(size[0])
        self.boardY = int(size[1])
        self.board = []
        for counter in range (0,self.boardX):
            line = file.readline()
            self.board.append(list(line[:-1]))
        self.words = file.readline()
        self.words = self.words.split(" ")
        print("READ DATA SUCCESSFULLY")

    def __str__ (self):
        result = ""
        result += "BOARD SIZE:" + str(self.boardX) + " " + str(self.boardY) + "\n"
        result += "BOARD:\n"
        for line in self.board:
            result += str(line) + "\n"
        result += "WORDS:\n"
        result += str(self.words) + "\n"
        return result

    def initPopulation(self):
        for ct in range(0,self.populationSize):
            genome = list(range(0, len(self.words)))
            shuffle(genome)
            newIndividual = Individual(self.words,genome.copy(),deepcopy(self.board),self.listOfSpaces,self.splitmark)
            newIndividual.evalFitness()
            self.population.append(newIndividual)
            print("CREATING INDIVIDUAL #" + str(ct) + "WITH " + str(newIndividual.fitness) + " FITNESS")
        self.population = Population(self.population)

    # here we process the black spots, words and board to find how we can split the
    # list of words in horizontal and vertical word lists
    def processBoard(self):
        print("PROCESSING BOARD")

        minimumWordLength = 100 #arbitrary
        for word in self.words:
            if len(word) < minimumWordLength:
                minimumWordLength = len(word)
        #this will contain a list of numbers of spaces corresponding to each word space on the board

        listOfSpaces = []
        for ct1 in range (0,self.boardY):
            nrOfSpaces = 0
            auxX = -1
            auxY = -1
            for ct2 in range (0,self.boardX):
                if self.board[ct1][ct2] == '0' :
                    nrOfSpaces += 1
                    if( auxY + auxX == -2):
                        auxY = ct1
                        auxX = ct2
                if self.board[ct1][ct2] == '1':
                    if nrOfSpaces >= minimumWordLength:
                        listOfSpaces.append([nrOfSpaces,[auxY,auxX]])
                    nrOfSpaces = 0
                    auxY = -1
                    auxX = -1

            if nrOfSpaces >= minimumWordLength:
                listOfSpaces.append([nrOfSpaces,[auxY,auxX]])

        #the vertical words start from here
        self.splitmark = len(listOfSpaces)
        for ct1 in range (0,self.boardX):
            nrOfSpaces = 0
            auxX = -1
            auxY = -1
            for ct2 in range(0, self.boardY):
                if self.board[ct2][ct1] == '0':
                    nrOfSpaces += 1
                    if (auxY + auxX == -2):
                        auxY = ct1
                        auxX = ct2
                if self.board[ct2][ct1] == '1':
                    if nrOfSpaces >= minimumWordLength:
                        listOfSpaces.append([nrOfSpaces,[auxX,auxY]])
                    nrOfSpaces = 0
                    auxY = -1
                    auxX = -1
            if nrOfSpaces >= minimumWordLength:
                listOfSpaces.append([nrOfSpaces,[auxX,auxY]])
        self.listOfSpaces = listOfSpaces
        print("FINISHED PROCESSING BOARD")
        print(self.listOfSpaces)

    def __init__(self, dataFilename, paramsFilename):
        print("INITIALISING PROBLEM FROM FILES: " + dataFilename + ", " + paramsFilename)
        self.population = []
        self.splitmark = -1
        self.readData(dataFilename)
        self.readParams(paramsFilename)
        self.processBoard()
        print(self)
        self.initPopulation()
        print("FINISHED INITIALISING PROBLEM")


class EvolutiveAlgorithm:

    def statistics(self):
        bestFitness = self.population.listOfIndividuals[0].fitness
        bestIndividual = -1
        avarageFitness = 0
        for individual in self.population.listOfIndividuals:
            avarageFitness += individual.fitness
            if individual.fitness <= bestFitness:
                bestFitness = self.population.listOfIndividuals[0].fitness
                bestIndividual = deepcopy(individual)
        avarageFitness = float(avarageFitness) / self.populationSize
        return [bestFitness,deepcopy(bestIndividual)]

    def run(self):
        bestFitness = 500
        bestIndividual = []
        for ct in range(0,self.problem.noGenerations):
            self.iteration()
            pair = self.statistics()
            if pair[0] < bestFitness:
                bestFitness = pair[0]
                bestIndividual = pair[1]
                print("ITERATION #" + str(ct) + " FITNESS " + str(pair[0]))
            if ct % 100 == 0:
                print("ITERATION #" + str(ct) + " FITNESS " + str(pair[0]))
        print("BEST INDIVIDUAL: ")
        if(len(set(bestIndividual.genotype)) == len(bestIndividual.genotype)):
            print(bestIndividual)


    def iteration(self):
        newPopulation = []
        shuffle(self.population.listOfIndividuals)
        for ct in range(0,self.populationSize,2):
            parent1 = self.population.listOfIndividuals[ct]
            parent2 = self.population.listOfIndividuals[ct+1]
            genome = list(range(0, len(self.problem.words)))
            #newIndividual = deepcopy(parent1)
            #newIndividual.cycleCrossover(parent2,self.problem.crossoverFactor)
            newIndividual = Individual(self.problem.words, genome, self.problem.board, self.problem.listOfSpaces, self.splitMark)
            newIndividual.crossover(parent1,parent2)
            newIndividual.mutate(self.problem.mutationFactor)
            newIndividual.evalFitness()
            newPopulation.append(newIndividual)
        for kid in newPopulation:
            self.population.listOfIndividuals.append(kid)
        self.population.listOfIndividuals.sort(key=lambda x: x.fitness, reverse=False)
        self.population.listOfIndividuals = self.population.listOfIndividuals[:self.populationSize]


    def __init__(self, problem):
        self.problem = problem
        self.splitMark = problem.splitmark
        self.population = problem.population
        self.populationSize = problem.populationSize

myProblem = Problem("data.in","params.in")
myAlgo = EvolutiveAlgorithm(myProblem)
print("PROCEED WITH ITERATIONS?")
x = "yes"
while x != "no":
    x = input()
    x = x.split(" ")
    if(len(x) > 1):
        myProblem.mutationFactor = float(x[1])
    print("MUTATION FACTOR:" + str(myProblem.mutationFactor))
    myAlgo.run()

#print(myProblem)