# /usr/bin/env python 
# -*- conding: utf-8 -*-

class Countdown(object):
	def __init__(self, num):
		self.num = num
	
	def __iter__(self):
		return self

	def next(self):
		self.num -= 1
		if self.num == 0:
			raise StopIteration
		return self.num

i1 = Countdown(5)
print i1.next()
print i1.next()
print i1.next()
print i1.next()
print i1.next()
print i1.next()
