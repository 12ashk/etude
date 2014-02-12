# /usr/bin/env python
#! -*- coding: utf-8 -*-

import sys
import re
import random

def complete_number(num):
	div = 1
	for i in range(2, num):
		if num % i == 0:
			div += i
	if div == num:
		return num 
	else:
		return False

def leap_year(num):
	if num % 400 == 0:
		return num
	elif num % 4 == 0 and num % 100 != 0:
		return num
	else:
		return False

def fact():
	i = 0
	x = 1
	while True:
		i += 1
		x *= i
		yield x

def factorial():
	Fact = fact()
	print [next(Fact) for i in range(input())]
	
def ackerman(x, i):
	print x,
	if x == 1:
		print '\nstep: %d' % i
		return 1
	if x % 2 == 0:
		return ackerman(x/2, i+1)
	else:
		return ackerman(3*x + 1, i+1)
	
def randlist(size, lower = 0, upper = 100):
	return [random.randint(lower, upper) for i in range(size)]

def qsort(lst):
	if lst == []:
		return lst
	else:
		x, xs = lst[0], lst[1:]
		return qsort([a for a in xs if a < x ]) + [x]\
				+ qsort([a for a in xs if a >= x])

def rev_qsort(lst):
	if lst == []:
		return lst
	else:
		x, xs = lst[0], lst[1:]
		return rev_qsort([a for a in xs if a > x ]) + [x]\
				+ rev_qsort([a for a in xs if a <= x])

def wnum_qsort(lst):
	if lst == []:
		return lst
	else:
		x, xs = lst[0], lst[1:]
		return wnum_qsort([a for a in xs if len(a) < len(x) ]) + [x]\
				+ wnum_qsort([a for a in xs if len(a) >= len(x)])

def par(filename1, filename2):
	file1 = open(filename1)
	file2 = open(filename2)

	ls = file1.read().split('\n')
	width = max(map(len, ls))
	ls = [s.ljust(width) for s in ls]

	output(ls, width, file2.read().split('\n'))

	file1.close()
	file2.close()

def output(lls, lwidth, rls):
	llen, rlen = len(lls), len(rls)
	s = '' * lwidth
	
	for i in range(max(llen, rlen)):
		if i < llen:
			print lls[i],
			if i < rlen:
				print '| %s' % rls[i]
			else:
				print '|'
		else:
			print '%s | %s' % (s, rls[i])

if __name__ == '__main__':
	if len(sys.argv) != 3:
		print 'usage: pytohn par.py file1 file2'
	else:
		par(sys.argv[1], sys.argv[2])
