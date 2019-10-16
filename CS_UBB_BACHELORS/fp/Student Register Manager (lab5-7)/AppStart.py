from handler.StudHandler import StudHandler
from handler.AssignHandler import AssignHandler
from handler.LinkHandler import LinkHandler
from repo.StudentRepo import StudentRepo
from repo.AssignRepo import AssignRepo
from repo.LinkRepo import LinkRepo
from ui.UI import UI
class AppStart():
    '''
    Starts application
    '''
    def __init__(self,ui):
        self._ui = ui
    def call(self):
        self._ui.loop()

srepo = StudentRepo()
arepo = AssignRepo()
lrepo = LinkRepo()
linkid = 0
ashandler = AssignHandler(arepo)
sthandler = StudHandler(srepo)
linkhandler = LinkHandler(arepo,srepo,lrepo,linkid)
ui = UI(ashandler,sthandler,linkhandler)
appstart = AppStart(ui)
ui._sthandler._studrepo.readfromfile()
ui._ashandler._assignrepo.readfromfile()
for counter in ui._sthandler._studrepo._data:
    newassign = ui._ashandler._assignrepo.findById(counter.getID())
    ui._linkhandler.makeLink(newassign,counter)
appstart.call()
