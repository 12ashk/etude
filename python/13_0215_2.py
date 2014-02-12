#! /usr/bin/env python
# -*- coding: utf-8 -*-

import Tkinter as Tk

class Frame(Tk.Frame):
	def __init__(self, master = None):
		Tk.Frame.__init__(self, master)
		self.master.title('Pack Three Labels')
		
		la = Tk.Label(self, text = 'Hello everyone. How are you?', bg = 'yellow', relief = Tk.RIDGE, bd = 2)
		la.place(relx = 0.02, rely = 0.1, relheight = 0.3, relwidth = 200)

		lb = Tk.Label(self, text = 'Oh My God!', bg = 'red', relief = Tk.RIDGE, bd = 2)
		lb.place(relx = 0.15, rely = 0.45)

		lc = Tk.Label(self, text = 'See you tomorrow.', bg = 'LightSkyBlue', relief = Tk.RIDGE, bd = 2)
		lc.place(relx = 0.5, rely = 0.75)

if __name__ == '__main__':
	f = Frame()
	f.pack()
	f.mainloop()

