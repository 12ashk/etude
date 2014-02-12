#! /usr/bin/env python
# -*- coding: utf-8 -*-
import time

if __name__ == '__main__':
	first = time.clock()
	n = 600851475143
	lst = []
	if n % 2 == 0:
		lst.append(2)
	for i in xrange(3, n/2, 2):
		if n % i == 0:
			f = True
			for j in lst:
				if i % j == 0:
					f = False
					break
			if f:
				lst.append(i)
		if i**2 > n:
			break

	for i in lst:
		print i, 
	print 'time: ', time.clock() - first
