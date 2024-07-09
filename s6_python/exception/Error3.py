def fun(a):
    if(a<4):
        b=a/(a-3)
    print("value of b=",b)
try:
    
    fun(4)
    fun(3)

except UnboundLocalError:
    print("UnboundedLocal error handled")
except NameError:
    print("Name Error catched and Handled")
except ZeroDivisionError:
    print("Zero division Error occured and handled")
#final Error will be considered as the default error