

class StudentError(BaseException):
    '''
    StudentError exception, answers for errors residing in the Student class context 
    '''
    def __init__(self, msg):
        self._msg = msg
        
    def __str__(self):
        return self._msg
