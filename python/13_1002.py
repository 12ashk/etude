#! /usr/bin/env python
# -*- coding: utf-8 -*-
import numpy
from HHM import Runge_Kutta

class test(Runge_Kutta):
	def __init__(self):
		Runge_Kutta.__init__(self)
		self.k = 10

	def functions(self, t, x):
		return -self.k * x 

	def solve(self):
		t = 0
		for i in xrange(0, self.time-1):
			t += self.dt
			self.y[i+1] = self.solver(t, self.y[i])

if __name__ == '__main__':
	t = test()
	t.change_parameter(1, 0.001, 0.1)
	t.solve()
	t.show_graph()

