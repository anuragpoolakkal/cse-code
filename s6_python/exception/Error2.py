def AbyB(a,b):
    try:
        c=((a+b)/(a-b))
    except ZeroDivisionError:
        print("Cannot divide a=b")
    else:
        print(c)
AbyB(2.0,3.0)
AbyB(3.0,3.0)