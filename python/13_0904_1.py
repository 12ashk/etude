#! /usr/bin/env python
# -*- coding: utf-8 -*-
# Range Minimum Query by Segment Tree

MAX_NUM = 100000
class SegTree(object):
	global MAX_NUM
	def __init__(self, max_num):
		self.max_num = max_num
		n = 1
		while self.max_num > n:	n *= 2
		self.n = n
		self.data = [MAX_NUM]*(2*n-1)
	
	def _update(self, i):
		self.data[i] = min(self.data[i*2+1], self.data[i*2+2])
		if i <= 0:
			return
		self._update((i-1)/2)

	def update(self, i, x):
		i += self.n - 1
		self.data[i] = x
		self._update((i-1)/2)
	
	def query(self, a, b):
		return self._query(a, b, 0, 0, self.n)

	def _query(self, a, b, k, left, right):
		if right <= a or left >= b:
			return MAX_NUM 
		elif a <= left and right <= b:
			return self.data[k]
		else:
			vl = self._query(a, b, 2*k+1, left, (left+right)/2)
			vr = self._query(a, b, 2*k+2, (left+right)/2, right)
			return min(vl, vr)

	def print_data(self):
		print self.data[self.n-1:self.n-1+self.max_num]
	
if __name__ == '__main__':
	import random
	lst = SegTree(10)
	for i in xrange(10):
		lst.update(i, random.randrange(100))
	lst.print_data()
	print lst.query(0, 4)
