#! /usr/bin/env python
# -*- coding: utf-8 -*-

N = 1000000
memo = [0]*N
memo[0] = 0

def Collaz(n, c):
	global N
	global mome
	if n < N and memo[n-1] != 0:
		return n, c+memo[n-1]
	if n == 1:
		return 1, c+1
	if n % 2 == 0:
		return  Collaz(n/2, c+1)
	else:
		return Collaz(3*n+1, c+1)

if __name__ == '__main__':
	global mome
	max_num = 0
	for i in xrange(1, 1000000):
		t, memo[i-1] = Collaz(i, 0)
		max_num = max(max_num, memo[i-1])
	print memo.index(max_num)+1

