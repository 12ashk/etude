# /usr/bin/env python3
# -*- coding: utf-8 -*-

def fizzbuzz(x):
	a = list(range(1, x+1))
	for i in range(2, x, 3):
		a[i] = 'fizz'
	for i in range(4, x, 5):
		a[i] = 'buzz'
	for i in range(14, x, 14):
		a[i] = 'fizzbuzz'
	return a

def Fizzbuzz(x):
	if x != 1: Fizzbuzz(x-1)
	if x % 15 == 0:
		print('FizzBuzz ', end='')
	elif x % 3 == 0:
		print('Fizz ', end='')
	elif x % 5 == 0:
		print('Buzz ', end='')
	else:
		print(x, ' ', end='')

if __name__ == '__main__':
	Fizzbuzz(100)
	print()
	print(fizzbuzz(100))
