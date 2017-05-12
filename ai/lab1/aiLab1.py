from random import shuffle
from copy import deepcopy
import math
#1 2 3 4 .. n
#2 3 1

def createCammels (number):
    cammels = []
    for i in range (0,number):
        cammels.append(i)
    return cammels

def checkSolutionValidity (candidate, originalCammels):
    if fitness(candidate, originalCammels) == 0:
        return True
    return False

def fitness(candidate, originalCammels):
    score = 0 #if this stays 0 then the solution is purfect
    for ct in range(0, len(candidate) - 1):
        if candidate[ct + 1] - candidate[ct] == 1:
            score += 1
    return score

def generateCandidate(originalCammels):
    candidate = deepcopy(originalCammels)
    shuffle(candidate)
    return candidate

def getMeanAndSD(number, numberOfTrials):
    print("START")
    originalCammels = createCammels(number)
    print("CAMMELS CREATED")
    fitnessValues = []
    mean = 0
    for i in range(0, numberOfTrials):
        candidate = generateCandidate(originalCammels)
        print("CANDIDATE ", i, " WAS GENERATED: ", candidate)
        fitnessValues.append(fitness(candidate, originalCammels))
        mean += fitnessValues[i]
    mean /= numberOfTrials
    print("CALCULATED MEAN")
    auxSum = 0 # (f(i) - m )^2
    for i in range (0,numberOfTrials):
        auxSum += math.pow((fitnessValues[i] - mean),2)
    standardDeviation = math.sqrt(auxSum/numberOfTrials)
    print("CALCULATED STANDARD DEVIATION")
    return mean, standardDeviation

result = getMeanAndSD(1000,100)
print("FINISHED")
print(result)