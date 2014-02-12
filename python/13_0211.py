# /usr/bin/env python
# -*- coding: utf-8 -*-

class MyIterator(object):
	def __init__(self, step):
		self.step = step
	def next(self):
		"""returns the next element."""
		if self.step == 0:
			raise StopIteration
		self.step -= 1
		return self.step
	__next__ = next # for python 3.x
	def __iter__(self):
		"""returns the iterator itself."""
		return self

def fibonaci():
	a, b = 0, 1
	while True:
		yield b
		a, b = b, a+b

def power(values):
	for value in values:
		print 'powering %s' % (value)
		yield value

def adder(values):
	for value in values:
		print 'adding to %s' % (values)
		if value % 2 == 0:
			yield value + 3
		else:
			yield value + 2

def psychologist():
	print 'please tell me your problem'

	while True:
		answer = yield
		if answer.endswith('?'):
			print "Don't ansk your self too much questions"
		elif 'good' in answer:
			print "A thiat's good, go on"
		elif 'bad' in answer:
			print 'Don\'t be so negative'

def FizzBuzz():
	i = 1
	while True:
		if i % 15 == 0:
			yield 'FizBuzz'
			i += 1
		elif i % 3 == 0:
			yield 'Fizz'
			i += 1
		elif i % 5 == 0:
			yield 'Buzz'
			i += 1
		else:
			yield i
			i += 1

def main():
	fizzbuzz = FizzBuzz()
	print [next(fizzbuzz) for i in range(input())]

if __name__ == '__main__':
	main()
