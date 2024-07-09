try:
    raise NameError("hi there")
except NameError as e:
    print("An exception "+ repr(e)) #representation
    print("An Exception "+ str(e)) #string takes an object and returns a string representation
