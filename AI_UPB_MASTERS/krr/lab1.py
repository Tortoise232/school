from copy import deepcopy
from enum import IntEnum

class Op(IntEnum):
    NOT = 0
    AND = 1
    OR = 2
    IMP = 3
    DIMP = 4
    DNEG = 5
    NAND = 6
    NOR = 7
    NIMP = 8
    NDIMP = 9


def checkValidity(dictionary, key, value):
    print("Checking: " + str(dictionary) + " " + str(key) + " " + str(value))
    valueInDict = dictionary.get(key)
    if valueInDict is None or valueInDict is value:
        return True
    return False


class Node:
    def __init__(self, value_dict, statements):
        self.dict = deepcopy(value_dict)
        self.statements = deepcopy(statements)

    def expand(self):
        for stmt in self.statements:
            isInconsistent = False
            #simple value
            if not isinstance(stmt, Op) and not isinstance(stmt, list):
                if not checkValidity(self.dict, stmt, True):
                    isInconsistent = True
                self.dict[stmt] = True
            #expression that needs to be expanded
            else:
                # prepare new statements for new node
                newStatements = deepcopy(self.statements)
                newStatements.remove(stmt)

                if stmt[0] == Op.NOT:
                    #negated value
                    if not isinstance(stmt[1], list):
                        if not checkValidity(self.dict, stmt[1], False):
                            print("FOUND INCONSISTENCY")
                            isInconsistent = True
                        self.dict[stmt[1]] = False
                    #negated statement
                    else:
                        #double negation
                        if stmt[1][0] == Op.NOT:
                            newStatements.append(stmt[1][1])
                        #negating AND-DIMP
                        if stmt[1][0] >= Op.AND and stmt[1][0] <= Op.DIMP:
                            stmt[1][0] = Op(stmt[1][0] + 5)
                            newStatements.append(stmt[1])
                        #negating NAND-NDIMP
                        if stmt[1][0] >= Op.NAND:
                            stmt[1][0] = Op(stmt[1][0] - 5)
                            newStatements.append(stmt[1])

                        newNode = Node(self.dict, newStatements)
                        newNode.expand()

                if stmt[0] == Op.AND:
                    newStatements.append(stmt[1])
                    newStatements.append(stmt[2])
                    newNode = Node(self.dict, newStatements)
                    newNode.expand()

                if stmt[0] == Op.NOR:
                    newStatements.append([Op.NOT, stmt[1]])
                    newStatements.append([Op.NOT, stmt[2]])
                    newNode = Node(self.dict, newStatements)
                    newNode.expand()

                if stmt[0] == Op.NIMP:
                    newStatements.append(stmt[1])
                    newStatements.append([Op.NOT, stmt[2]])
                    newNode = Node(self.dict, newStatements)
                    newNode.expand()

                if stmt[0] == Op.OR:
                    newStatements.append(stmt[1])
                    nodeLeft = Node(self.dict, newStatements)
                    nodeLeft.expand()

                    newStatements.remove(stmt[1])
                    newStatements.append(stmt[2])
                    nodeRight = Node(self.dict, newStatements)
                    nodeRight.expand()


                if stmt[0] == Op.IMP:
                    leftStatement = [Op.NOT, stmt[1]]
                    newStatements.append(leftStatement)
                    nodeLeft = Node(self.dict, newStatements)
                    nodeLeft.expand()

                    newStatements.remove(leftStatement)
                    newStatements.append(stmt[2])
                    nodeRight = Node(self.dict, newStatements)
                    nodeRight.expand()

                if stmt[0] == Op.DIMP:
                    leftStatement = [Op.AND, stmt[1], stmt[2]]
                    newStatements.append(leftStatement)
                    nodeLeft = Node(self.dict, newStatements)
                    nodeLeft.expand()

                    newStatements.remove(leftStatement)
                    newStatements.append([Op.AND, [Op.NOT, stmt[1]], [Op.NOT, stmt[2]]])
                    nodeRight = Node(self.dict, newStatements)
                    nodeRight.expand()

                if stmt[0] == Op.NAND:
                    leftStatement = [Op.NOT, stmt[1]]
                    newStatements.append(leftStatement)
                    nodeLeft = Node(self.dict, newStatements)
                    nodeLeft.expand()

                    newStatements.remove(leftStatement)
                    newStatements.append([Op.NOT, stmt[2]])
                    nodeRight = Node(self.dict, newStatements)
                    nodeRight.expand()

                if stmt[0] == Op.NDIMP:
                    leftStatement = [Op.AND, stmt[1], [Op.NOT, stmt[2]]]
                    newStatements.append(leftStatement)
                    nodeLeft = Node(self.dict, newStatements)
                    nodeLeft.expand()

                    newStatements.remove(leftStatement)
                    newStatements.append([Op.AND, [Op.NOT, stmt[1]], stmt[2]])
                    nodeRight = Node(self.dict, newStatements)
                    nodeRight.expand()
        if not isInconsistent:
            print("Final truth values: " + str(self.dict))
            exit()

P1 = [[Op.IMP, 'W', 'P'], [Op.IMP, 'P', 'D'], [Op.IMP, 'D', 'F'], [Op.AND, 'W', [Op.NOT, 'D']]]
node = Node(dict(), P1)
node.expand()