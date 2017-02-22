
class AssignmentError(BaseException):
    '''
    Assignment Error, handles errors happening in the assignment class
    '''
    def __init__(self, msg):
        self._msg = msg
    def __str__(self):    
        return self._msg
    