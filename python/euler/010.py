#! /usr/bin/env python
# -*- coding: utf-8 -*-

def judge(n, lst):
	for i in lst:
		if n % i == 0:
			return False
	return True

def sum_prime(n):
	def prime(n):
		count = 2
		lst = [2]
		for i in xrange(3, n, 2):
			if judge(i, lst):
				lst.append(i)
				count += i
		return count
	return prime(n)

if __name__ == '__main__':
	print sum_prime(2000000)
