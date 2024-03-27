class sum:
    def add(self, a, b):
        return (a + b)

class multiplication (sum): # multiplication class inherits from the sum class
    def multiply (self, a, b):
        return (a * b)

class division (multiplication):
    def divide (self, a, b):
        if b == 0:
            return "Division by zero is invalid"
        return (a / b)

class subtraction (division):
    def subtract (self, a, b):
        return (a - b)

class number(division):
    op1 = 0
    op2 = 0

    def __init__(self, val1, val2):
        self.op1 = val1
        self.op2 = val2

    def all_ops (self):
        print (self.sum (self.val1, self.val2))

num_obj = number (4, 6)
num_obj.all_ops()