import tkinter
from tkinter import ttk
 
def add():
    num1 = float(num1_entry.get())
    num2 = float(num2_entry.get())
    result = num1 + num2
    result_label.config(text=result)
    
def sub():  
    num1 = float(num1_entry.get())
    num2 = float(num2_entry.get())
    result = num1 - num2
    result_label.config(text=result)

def mul():
    num1 = float(num1_entry.get())
    num2 = float(num2_entry.get())
    result = num1 * num2
    result_label.config(text=result)

def div():
    num1 = float(num1_entry.get())
    num2 = float(num2_entry.get())
    result = num1 // num2
    result_label.config(text=result)
 
# create the main window
root = tkinter.Tk()
root.title("Add Two Numbers")

my_frame=ttk.Frame(root,padding=100,width=800,height=250)
my_frame.grid()
my_frame.pack()

# create the widgets
num1_label = ttk.Label(my_frame, text="Number 1:", padding=10)
num1_entry = ttk.Entry(my_frame)
num2_label = ttk.Label(my_frame, text="Number 2:", padding=10)
num2_entry = ttk.Entry(my_frame)
add_button = ttk.Button(my_frame, text="Add", command=add, padding=10)
sub_button = ttk.Button(my_frame, text="Subtract", command=sub, padding=10)
mul_button = ttk.Button(my_frame, text="Multiply", command=mul, padding=10)
div_button = ttk.Button(my_frame, text="Divide", command=div, padding=10)
result_label = ttk.Label(my_frame, text="Result: ", padding=10)


# layout the widgets
num1_label.grid(row=0, column=0, sticky="e")
num1_entry.grid(row=0, column=1)
num2_label.grid(row=1, column=0, sticky="e")
num2_entry.grid(row=1, column=1)
add_button.grid(row=2, column=0, columnspan=2, pady=10, padx=10)
sub_button.grid(row=2, column=2, columnspan=2, pady=10)
mul_button.grid(row=4, column=0, columnspan=2, pady=10)
div_button.grid(row=4, column=2, columnspan=2, pady=10, padx=10)
result_label.grid(row=6, column=0, columnspan=2)
 
# run the main loop
root.mainloop()