import tkinter as tk
 
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
root = tk.Tk()
root.title("Add Two Numbers")

# create the widgets
num1_label = tk.Label(root, text="Number 1:")
num1_entry = tk.Entry(root)
num2_label = tk.Label(root, text="Number 2:")
num2_entry = tk.Entry(root)
add_button = tk.Button(root, text="Add", command=add)
sub_button = tk.Button(root, text="Subtract", command=sub)
mul_button = tk.Button(root, text="Multiply", command=mul)
div_button = tk.Button(root, text="Divide", command=div)
result_label = tk.Label(root, text="Result: ")


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