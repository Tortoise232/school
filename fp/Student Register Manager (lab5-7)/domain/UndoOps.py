
class AddOperation:
    
    def __init__(self,object):
        self._object = object
        
    def getObject(self):
        return self._object

    

class RemoveOperation:
    
    def __init__(self,object):
        self._object = object
        
    def getObject(self):
        return self._object
    
class UpdateOperation:
    def __init__(self,oldObject,newObject):
        self._oldObject = oldObject
        self._newObject = newObject
    
    def getOldObject(self):
        return self._oldObject
    
    def getNewObject(self):
        return self._newObject