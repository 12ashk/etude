#! /usr/bin/env python
# -*- coding: utf-8 -*-

def normal_fib(n):
	if n == 0:
		return 1
	elif n == 1:
		return 1
	return normal_fib(n-1) + normal_fib(n-2)

def memo_fib_body(n, memo):
	if memo[n] != 0:
		return memo[n]
	memo[n] = memo_fib_body(n-1, memo) + memo_fib_body(n-2, memo)
	return memo[n]

def memo_fib(n):
	memo = [0] * n
	memo[0] = memo[1] = 1
	return memo_fib_body(n-1, memo)

def dp_fib(n):
	dp = [0]*n
	dp[0] = dp[1] = 1
	for i in xrange(2, n):
		dp[i] = dp[i-1]+dp[i-2]
	return dp[n-1]

if __name__ == '__main__':
	print normal_fib(10-1)
	print memo_fib(10)
	print dp_fib(10)
