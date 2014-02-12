#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import re
import os
from datetime import date

def get_date():
	return str(date.today())

def imput_data():
	f = open('cash_book.txt', 'a')
	f.write(get_date())
	f.write('\t')
	f.write(sys.argv[2])
	f.write('\t')
	f.write(str(sys.argv[3]))
	f.write('\n')
	f.close()

def summary():
	f = open('cash_book.txt')
	data = f.readline().split('\t')
	result, pre = int(data[1]), data[0]
	for l in f:
		data = l.split('\t')
		if pre == data[0]:
			result += int(data[1])
		else:
			pre = data[0]
			result = int(data[1])
	if pre == data[0]:
		print '%s\t%d' % (pre, result)
	f.close()

def applicate():
	f = open('cash_book.txt')
	dict_list = {}
	for l in f:
		temp =  l.split('\t')
		temp[2] = re.split('\n', temp[2])[0]
		if dict_list.get(temp[2], False):
			dict_list[temp[2]] = dict_list.get(temp[2]) + int(temp[1])
		else:
			dict_list[temp[2]] = int(temp[1])
	f.close()
	dict_sort(dict_list)
	
def dict_sort(d_list):
	temp = sorted(d_list, key = lambda x: d_list.get(x))
	for l in temp:
		print l, d_list[l]

if __name__ == '__main__':
	if sys.argv[1] == 'add':
		imput_data()
	elif sys.argv[1] == 'summary':
		summary()
	elif sys.argv[1] == 'application':
		applicate()
	else:
		print '--'
