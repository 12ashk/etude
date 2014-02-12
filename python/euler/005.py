#! /usr/bin/env python
# -*- coding: utf-8 -*-
import time

def gcd(a, b):
	if a % b == 0:
		return b
	else:
		return gcd(b, a%b)

def lcm(a, b):
	t = gcd(a, b)
	return a*b/t

if __name__ == '__main__':
	first = time.clock()
	ans = 1
	for i in xrange(2, 21):
		ans = lcm(ans, i)

	print ans, 'time: ', time.clock() - first

