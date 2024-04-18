import tkinter
from tkinter import ttk, messagebox
import math

def squareroot():
    try:
        input_number = int(input_entry.get())
        if input_number < 0:
            raise ValueError("Number must be positive")
        sqrt = math.sqrt(input_number)
        output.config(text=f"Square root: {sqrt}")
    except ValueError as e:
        messagebox.showerror("Error", "Please enter a valid number.")
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {e}")

root = tkinter.Tk()
root.title("Calculate squareroot")

myframe = ttk.Frame(root, padding=100, height=300, width=300)
myframe.grid()
myframe.pack()

input_label = ttk.Label(myframe, text="Enter number: ", padding=10)
input_entry = ttk.Entry(myframe)
convert_button = ttk.Button(myframe, text="Calculate squareroot", command=squareroot, padding=10)
output = ttk.Label(myframe, padding=10)

input_label.grid(column=1, row=1)
input_entry.grid(column=2, row=1)
convert_button.grid(column=1, row=2)
output.grid(column=1, row=3)

root.mainloop()