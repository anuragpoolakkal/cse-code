import tkinter
from tkinter import ttk

def convert():
    user_text = input_entry.get()
    converted_input = user_text.upper()
    converted_text.config(text=converted_input)

root = tkinter.Tk()
root.title("Convert to Uppercase")

myframe = ttk.Frame(root, padding=100, height=300, width=300)
myframe.grid()
myframe.pack()

input_label = ttk.Label(myframe, text="Enter text: ", padding=10)
input_entry = ttk.Entry(myframe)
convert_button = ttk.Button(myframe, text="Convert to Uppercase", command=convert, padding=10)
converted_text = ttk.Label(myframe, text="Converted text: ", padding=10)

input_label.grid(column=1, row=1)
input_entry.grid(column=2, row=1)
convert_button.grid(column=1, row=2)
converted_text.grid(column=1, row=3)

root.mainloop()