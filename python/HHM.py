#! /usr/bin/env python
# -*- coding: utf-8 -*-
import pylab 

class ODE(object):
	def __init__(self):
		self.dt = 0.001
		self.time = (int)(80./self.dt)
		self.y = [0]*self.time
	def change_parameter(self, init, dt, time):
		self.dt = dt
		self.time = (int)(time/self.dt)
		self.y = [0]*self.time
		self.y[0] = init
	
	def show_graph(self):
		pylab.plot(self.y)
		pylab.show()

	def solve(self):
		pass

	def solver(self):
		pass

	def functions(self):
		pass

# solved by runge kutta method
class Runge_Kutta(ODE):
	def solver(self, t, x):
		k1 = self.functions(t, x)
		k2 = self.functions(t+0.5*self.dt, x+0.5*k1)
		k3 = self.functions(t+0.5*self.dt, x+0.5*k2)
		k4 = self.functions(t+self.dt, x+k3)
		return x + self.dt*(k1+2*k2+2*k3+k4)/6.0
													
# this class is hodgkin huxley model
class HMM(Runge_Kutta):
	def __init__(self):
		ODE.__init__(self)
		self.Er = -65.0
		self.y[0] = -70.
		self.Ena = -15.
		self.Ek = -142.
		self.El = -119.387
		self.gna = -127.0
		self.gk = 36.0
		self.gl = 0.3
		self.Cm = 1.0
		self.Istm = [0]*self.time
		for i in xrange((int)(20/self.dt), (int)(23/self.dt)+1):
			self.Istm[i] = 6.
		self.calc_paras(0)
		self.m = self.am/(self.am+self.bm)
		self.h = self.ah/(self.ah+self.bh)
		self.n = self.an/(self.an+self.bn)
		self.Vk = self.Ek-self.Er
		self.Vna = self.Ena-self.Er
		self.Vl = self.El-self.Er

	def solver(self, x, i):
		k1 = self.functions(x, i)
		k2 = self.functions(x+0.5*k1, i)
		k3 = self.functions(x+0.5*k2, i)
		k4 = self.functions(x+k3, i)
		return x + self.dt*(k1+2*k2+2*k3+k4)/6

	def functions(self, x, i):
		# dm/dt
		if(i == 0):
			return self.am*(1-x)-self.bm*x
		# dh/dt
		if(i == 1):
			return self.ah*(1-x)-self.bh*x
		# dn/dt
		if(i == 2):
			return self.an*(1-x)-self.bn*x
		# dV/dt
		if(i == 3):
			return self.Im/self.Cm

# this function use in both __init__ and solve
	def calc_paras(self, V):
		self.am = (4.+0.1*V)/(1.-pylab.exp(-5.5-0.1*V))
		self.bm = 4.*pylab.exp(0.0556*V-3.614)
		self.ah = 0.07*pylab.exp(-3.25-0.05*V)
		self.bh = 1./(pylab.exp(-3.5-0.1*V)+1.)
		self.an = (0.55+0.01*V)/(1-pylab.exp(-5.5-0.1*V))
		self.bn = 0.125*pylab.exp(-0.0125*V-0.8125)

	def solve(self):
		def calc_parameters(V, stm):
			self.calc_paras(V)
			self.Ik = self.gk*(self.n**4)*(V-self.Vk)
			self.Ina = self.gna*(self.m**3)*self.h*(V-self.Vna)
			self.Il = self.gl*(V-self.Vl)
			self.Im = stm-(self.Ik+self.Ina+self.Il)

		for i in xrange(self.time-1):
			calc_parameters(self.y[i], self.Istm[i])
			self.y[i+1] = self.solver(self.y[i], 3)
			self.m = self.solver(self.m, 0)
			self.h = self.solver(self.h, 1)
			self.n = self.solver(self.n, 2)

def main():
	a = HMM()
	a.solve()
	a.show_graph()

if __name__ == '__main__':
	main()
