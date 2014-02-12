#! /usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np

def LU_decomposition(a):
	for k in xrange(len(a)-1):
		omega = 1. / a[k][k]
		for i in xrange(k+1, len(a)):
			a[i][k] *= omega
			for j in xrange(k+1, len(a)):
				a[i][j] -= a[i][k] * a[k][j]
	return a

def solve(a, b):
	y = [0]*len(a)
	y[0] = b[0]
	for i in xrange(1, len(a)):
		s = 0
		for j in xrange(i):
			s += a[i][j] * y[j]
		y[i] = b[i] - s
	
	x = [0]*len(a)
	x[-1] = y[-1]/a[-1][-1]
	for i in xrange((len(a)-2), -1, -1):
		s = 0
		for j in xrange(i+1, len(a)):
			s += a[i][j] * x[j]
		x[i] = (y[i]-s)/a[i][i]

	return x

def main():
	a = [[1., 2., 3., 4.], [4., 2., 6., 7.], [7., 8., 4., 10.], 
			[10., 9., 4., 12]]
	b = [1, 2, 3, 4]
	a = LU_decomposition(a)
	x = solve(a, b)
	for i in x:
		print '%.2f' % i

if __name__ == '__main__':
	main()
