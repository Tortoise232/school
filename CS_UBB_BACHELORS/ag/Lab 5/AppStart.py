from domain.UndirectedGraph import Graph
from Repository.Repository import Repository
from controller.Controller import Controller
from ui.UI import UI
graph = Graph()
repo = Repository(graph)
repo.loadFromFile()
controller = Controller(repo)
ui = UI(controller)
#print(ui._controller.getAllVertices())
ui.mainLoop()
#print(ui._controller.biconnectedGraph())
