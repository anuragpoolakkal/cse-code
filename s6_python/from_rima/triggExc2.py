class MyError(Exception):
    def __init__(self,value):
        self.value=value
    def __str__(self):
        return(repr(self.value))

try:
    raise MyError(3*2)
except MyError as e:
    print("A new exception occured: ",e.value)