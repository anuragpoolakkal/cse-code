#No exception handling no output from compiler. 
x=5
y="hello"
try:
    z=x+y #unsafe operations are put inside the try block
except TypeError:
    print("Error cannot add integer and string")
