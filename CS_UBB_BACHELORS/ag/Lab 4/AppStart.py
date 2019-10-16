from domain.DoubleDirectedGraph import Graph
from Repository.Repository import Repository
from controller.Controller import Controller
from ui.UI import UI
file = open("data.txt","r")
nr_of_vertices = file.readline()
nr_of_vertices = nr_of_vertices.split(" ")
file.close()
#newLine = file.readline()
#newLine = newLine.split(" ")

graph = Graph(int(nr_of_vertices[0]))
repo = Repository(graph)
repo.loadFromFile()
controller = Controller(repo)
ui = UI(controller)
ui.mainLoop()

#DO NOT REMOVE VERTICES THEY ALWAYS COME BACK LOL