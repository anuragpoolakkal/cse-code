import time

def fibonacci(num):
    if num <= 0:
        return ("Invalid")
    if num == 1:
        return 0
    if num == 2:
        return 1
    return fibonacci(num - 1) + fibonacci(num - 2)

start = time.time()
print(fibonacci(40))
end = time.time()

print("Time taken by fibonacci:", end - start)

def faster_fibonacci(num):
    if num <= 0:
        return ("Invalid")
    if num == 1:
        return 0
    if num == 2:
        return 1

    a = 0
    b = 1

    for i in range(2, num):
        c = a + b
        a = b
        b = c
    return c

start = time.time()
print(faster_fibonacci(40))
end = time.time()

print("Time taken by faster_fibonacci:", end - start)