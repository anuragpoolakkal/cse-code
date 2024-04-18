from turtle import Turtle
t = Turtle()

def hexagon(t, length):
    for count in range(6):
        t.forward(length)
        t.left(60)

hexagon(t, 100) 