#! /usr/bin/env python
# -*- coding:utf-8 -*-

if __name__ == '__main__':
	f = False
	for i in xrange(1, 1000):
		for j in xrange(i, 1000):
			k = 1000 - i - j
			if(i**2 + j**2 == k**2):
				print i, j, k
				f = True
				break
		if f: break
