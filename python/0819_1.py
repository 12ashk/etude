# /usr/bin/env python
# -*- coding: utf-8 -*-

class myclass:
	a = 10
	def __init__(b):
		print b.a
	def set_a(self, value):
		self.a = value
	def get_a(self):
		print self.a
	def delegation(self):
		self.action()

class delegate(myclass):
	def action(self):
		print 'a'


if __name__ == '__main__':
	a = myclass()
	a.get_a()
	b = myclass()
	b.set_a(100)
	b.get_a()
	c = delegate()
	c.delegation()
