#! /usr/bin/env python
# -*- coding: utf-8 -*-
import time

if __name__ == '__main__':
	first = time.clock()
	ans = 0
	for i in xrange(999, 100, -1):
		for j in xrange(i, 100, -1):
			t = str(i*j)
			if t == t[::-1] and ans < i*j:
					ans = i*j
	print ans
	print 'time: ', time.clock()-first
