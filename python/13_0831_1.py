#! /usr/bin/env python
# -*- coding: utf-8 -*-

tolerance = 0.005

def f(min_n, max_n):
	global tolerance
	temp = (max_n - min_n)/2 + min_n
	diff = temp**3 + temp**2 + temp - 1
	if abs(diff) < tolerance:
		return temp
	else:
		if diff < 0:
			return f(temp, max_n)
		else:
			return f(min_n, temp)

if __name__ == '__main__':
	print f(0, 1)
