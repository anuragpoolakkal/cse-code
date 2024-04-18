from tkinter import ttk
from tkinter import *

root=Tk(className="50")

my_frame=ttk.Frame(root,padding=100,width=300,height=250)
my_frame.grid()
my_frame.pack()

ttk.Label(my_frame,text="First Name").grid(column=1,row=0)
ttk.Label(my_frame,text="Last Name").grid(column=1,row=1)
ttk.Entry(my_frame).grid(row=0,column=2)
ttk.Entry(my_frame).grid(row=1,column=2)
ttk.Button(my_frame,text="Quit",command=root.destroy).grid(column=2,row=3)

root.mainloop()