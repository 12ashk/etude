#! /usr/bin/env python
# -*- coding: utf-8 -*-

import Tkinter as Tk

class Frame(Tk.Frame):
	def __init__(self, master = None):
		Tk.Frame.__init__(self, master)
		self.master.title('Pack Three Labels')
		
		la = Tk.Label(self, text = 'Hello everyone. How are you?', bg = 'yellow', relief = Tk.RIDGE, bd = 2)
		la.grid(row = 0, column = 0, columnspan = 2, padx = 5, 	pady = 5, sticky = Tk.W)

		lb = Tk.Label(self, text = 'Oh My God!', bg = 'red', relief = Tk.RIDGE, bd = 2)
		lb.grid(row = 1, column = 0, padx = 5, pady = 5)

		lc = Tk.Label(self, text = 'See you tomorrow.', bg = 'LightSkyBlue', relief = Tk.RIDGE, bd = 2)
		lc.grid(row = 1, column = 1, padx = 5, pady = 5)

if __name__ == '__main__':
	f = Frame()
	f.pack()
	f.mainloop()

