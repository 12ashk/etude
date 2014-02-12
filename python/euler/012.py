#! /usr/bin/env python
# -*- coding: utf-8 -*-

import math

def get_divisor_num(n):
	count = 2
	for i in xrange(2, int(math.sqrt(n))+1):
		if n % i == 0:
			count += 2
	return count

def triangele():
	n, t = 0, 0
	while True:
		n += 1
		t += n
		yield t

def main(n):
	num = 0
	i = 2
	tri = triangele()
	while num < n:
		i = tri.next()
		num = get_divisor_num(i)

	print num, i

if __name__ == '__main__':
	main(500)
