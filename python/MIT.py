# ~/usr/bin/env python
# -*- coding: utf-8 -*-

def sqrt(x):
	if x <= 0:
		return None
	else:
		i = 1
		while i**2 < x:
			i += 1
		if i ** 2 == x:
			return i
		else:
			return None

def Pigs_Chickens(heads, legs):
	for pigs in range(1, heads+1):
		chickens = heads - pigs
		if legs == 4*pigs + 2*chickens:
			return [pigs, chickens]
	return False
def barnYard():
	heads = input('Enter number of heads:')
	legs = input('Enter number of legs:')
	answer = Pigs_Chickens(heads, legs)
	if answer:
		print 'Number of pigs: %d' % (answer[0])
		print 'Number of birds: %d' % (answer[1])
	else:
		print 'There are no answer.'

def isPalindrome(x):
	if len(x) <= 1:
		return True
	else:
		if x[0] == x[-1] and isPalindrome(x[1:-1]):
			return True
		else:
			return False

def isPalindrome1(x, indent):
	print indent, 'isPalindrome: called with', x
	if len(x) <= 1:
		print indent, 'Above to return True from base case'
		return True
	else:
		ans = x[0] == x[-1] and isPalindrome1(x[1:-1], 2*indent)
		print indent, 'Above to return', ans
		return ans

def fib(x):
	if x == 0 or x == 1:
		return 1
	else:
		return fib(x-1) + fib(x-2)

def bi_sqrt(x, eps, guess, low, high):
	if abs(guess*guess - x) <= eps:
		return guess
	else:
		if guess*guess < x:
			low = guess
		else:
			high = guess
		return bi_sqrt(x, eps, (low+high)/2.0, low, high)

def run_bi_sqrt():
	x = input()
	eps = input()
	print bi_sqrt(x, eps, x/2.0, 0, max(1, x))

def Newton_sqrt(ans, eps):
	if abs(ans*ans - x) <= eps:
		return ans

def main():
	run_bi_sqrt()
if __name__ == '__main__':
	main()
