#! /usr/bin/env python
# -*- coding: utf-8 -*-

def combination(x, n):
	def comb(x, y):
		if y == []:
			return []
		else:
			return [x + [y[0]]] + comb(x, y[1:])

	if n > len(x):
		return []
	else:
		return comb(x[:n-1], x[n-1:]) + combination(x[1:], n)

if __name__ == '__main__':
	print combination([1, 2, 3, 4], 2)
