#! /usr/bin/env python
# -*- coding: utf-8 -*-
# implement union tree

MAX_NUM = 10
class UnionFind(object):
	global MAX_NUM
	def __init__(self):
		self.par = [i for i in xrange(MAX_NUM)]
	
	def find(self, x):
		if self.par[x] == x:
			return x
		else:
			self.par[x] = self.find(self.par[x])
			return self.par[x]
	
	def same(self, x, y):
		return self.find(x) == self.find(y)

	def union(self, x, y):
		x = self.find(x)
		y = self.find(y)
		if x == y:
			return 
		else:
			self.par[x] = y
	def __str__(self):
		return str(self.par[:])

if __name__ == '__main__':
	lst = UnionFind()
	print lst
	import random
	for i in xrange(5):
		lst.union(random.choice(lst.par), random.choice(lst.par))
	for i in xrange(5):
		print lst.find(i)
	print lst
