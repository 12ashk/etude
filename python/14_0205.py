#! /usr/bin/env python
#-*- coding: utf-8 -*-

def get_point():
	def get_string():
		N = int(raw_input())
		points = raw_input()
		points = map(int, points.split())
		return N, points
	
	def search(i, p):
		if i == 0:
			if p in lst: return
			lst.append(p)
		else:
			search(i-1, p)
			search(i-1, p+points[i-1])
	N, points = get_string()
	lst = []
	search(N, 0)
	print len(lst)

def fib(i):
	if i == 0: return 0
	elif i == 1: return 1
	else:
		return fib(i-1) + fib(i-2)

def memo_fib(i):
	def fib(i):
		if i == 0: return 0
		elif lst[i] != 0: return lst[i]
		else:
			return fib(i-1)+fib(i-2)
	lst = (i+1)*[0]
	lst[1] = 1
	return fib(i)

def dp_fib(n):
	import numpy as np
	dp = np.zeros(n+1, int)
	dp[1] = 1
	for i in xrange(2, n+1):
		dp[i] = dp[i-1]+dp[i-2]
	return dp[n]

def py_fib(n):
	pre = 0
	ans = 1
	for i in xrange(2, n+1):
		pre, ans = ans, ans+pre
	return ans

def main_fib():
	n = int(raw_input())
	import time
#	time1 = time.clock()
#	fib(n)
#	time2 = time.clock()
#	memo_fib(n)
#	time3 = time.clock()
#	dp_fib(n)
	time4 = time.clock()
	ans = py_fib(n)
	time5 = time.clock()
	print ans
#	print str(time2-time1)
#	print str(time3-time2)
#	print str(time4-time3)
	print str(time5-time4)

def fact(n):
	ans = 1
	for i in xrange(2, n+1):
		ans *= i
	return ans

def rec_fact(n):
	def fact(n, i):
		if i == 1: return n
		return fact(n*i, i-1)
	return fact(1, n)

def main_fact():
	n = int(raw_input())
	import time
	time1 = time.clock()
	ans2 = fact(n)
	time2 = time.clock()
	ans = rec_fact(n)
	time3 = time.clock()
	print ans2
	print str(time2-time1)
	print str(time3-time2)

if __name__ == '__main__':
	main_fact()
