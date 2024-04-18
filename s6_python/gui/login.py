import tkinter
from tkinter import ttk

root = tkinter.Tk()
root.title('Login')

my_frame = ttk.Frame(root, padding=100, width=700, height=250)
my_frame.grid()
my_frame.pack()

ttk.Label(my_frame, text='My Login Page').grid(column=1, row=1)
ttk.Label(my_frame, text='First Name').grid(column=1, row=2)
ttk.Label(my_frame, text='Last Name').grid(column=1, row=3)

ttk.Entry(my_frame).grid(row=2, column=2)
ttk.Entry(my_frame).grid(row=3, column=2)
ttk.Button(my_frame, text="Quit", command=root.destroy).grid(column=2, row=4)

root.mainloop()