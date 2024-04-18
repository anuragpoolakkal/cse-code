from tkinter import ttk
from tkinter import *

def add():
    num1=float((num1_entry.get()))
    num2=float((num2_entry.get()))
    result=num1+num2
    result_text="Sum:"+" "+str(result)
    result_label.config(text=result_text)

def subtract():
    num1=float((num1_entry.get()))
    num2=float((num2_entry.get()))
    result=num1-num2
    result_text="Difference:"+" "+str(result)
    result_label.config(text=result_text)

def multiply():
    num1=float((num1_entry.get()))
    num2=float((num2_entry.get()))
    result=num1*num2
    result_text="Product:"+" "+str(result)
    result_label.config(text=result_text)

def divide():
    num1=float((num1_entry.get()))
    num2=float((num2_entry.get()))
    result=num1/num2
    result_text="Quotient:"+" "+str(result)
    result_label.config(text=result_text)

root=Tk()

my_frame=ttk.Frame(root,padding=100,width=800,height=250)
my_frame.grid()
my_frame.pack()

num1_label=ttk.Label(my_frame,text="Number1",padding=10)
num1_entry=ttk.Entry(my_frame)
num2_label=ttk.Label(my_frame,text="Number2",padding=10)
num2_entry=ttk.Entry(my_frame)
add_button=ttk.Button(my_frame,text="ADD",command=add,padding=10)
sub_button=ttk.Button(my_frame,text="SUBTRACT",command=subtract,padding=10)
mul_button=ttk.Button(my_frame,text="MULTIPLY",command=multiply,padding=10)
div_button=ttk.Button(my_frame,text="DIVIDE",command=divide,padding=10)
result_label=ttk.Label(my_frame,text="Result:")

num1_label.grid(column=1,row=1)
num1_entry.grid(column=2,row=1)
num2_label.grid(column=1,row=2)
num2_entry.grid(column=2,row=2)
add_button.grid(column=1,row=3)
sub_button.grid(column=2,row=3)
mul_button.grid(column=3,row=3)
div_button.grid(column=4,row=3)
result_label.grid(column=2,row=6)

root.mainloop()