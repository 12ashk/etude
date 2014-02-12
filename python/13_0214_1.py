#! /usr/bin/env python
# -*- coding: utf-8 -*-

import Tkinter as Tk

class Frame(Tk.Frame):
	def __init__(self, master = None):
		Tk.Frame.__init__(self, master)
		self.master.title('Pack Three Labels')
		
		la = Tk.Label(self, text = 'Hello everyone. How are you?', bg = 'yellow', relief = Tk.RIDGE, bd = 2)
		la.pack(padx = 5)

		lb = Tk.Label(self, text = 'Oh My God!', bg = 'red', relief = Tk.RIDGE, bd = 2)
		lb.pack(padx = 5)

		lc = Tk.Label(self, text = 'See you tomorrow.', bg = 'LightSkyBlue', relief = Tk.RIDGE, bd = 2)
		lc.pack(anchor = Tk.W)

if __name__ == '__main__':
	f = Frame()
	f.pack()
	f.mainloop()
