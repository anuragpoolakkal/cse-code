class sum:
    def sum(self,a,b): #self corresponds to object of class sum - self reference object
        return a+b


#obj_sum=sum() #creating object
#print(obj_sum.sum(5,6))

class  multiplication(sum): #class  multilication is inheriting class sum
    def product(self,a,b):
        return a*b

"""obj_mul=multiplication()
print(obj_mul.sum(2,5))
print(obj_mul.product(2,5))"""

class division(multiplication):
    def quotient(self,a,b):
        return a/b


"""obj_div= division()
print(obj_div.sum(2,3))
print(obj_div.product(2,3))
print(obj_div.quotient(3,2))"""

#these classes does not hold any values. they perform operations
#creating new class which holds the numbers on which the value is stored

class number(division):
    operator_one=0
    operator_two=0

    def __init__(self, value_one,value_two):
        self.operator_one=value_one
        self.operator_two=value_two
    
    def all_operations(self):
        print(self.sum(self.operator_one,self.operator_two))
        print(self.product(self.operator_one,self.operator_two))
        print(self.quotient(self.operator_one,self.operator_two))


obj_number=number(6,5)
obj_number.all_operations()