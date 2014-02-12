#! /usr/bin/env python
# -*- coding: utf-8 -*-
import time

if __name__ == '__main__':
	first = time.clock()
	lst = []
	lst.append(2)
	for i in xrange(3, 200000, 2):
		f = True
		for j in lst:
			if i % j == 0:
				f = False
				break
		if f:
			lst.append(i)
		if len(lst) == 10001:
			break

	print lst[-1], 
	print 'time: ', time.clock() - first
