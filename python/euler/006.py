#! /usr/bin/env python
# -*- coding: utf-8 -*-

import time

if __name__ == '__main__':
	lst = range(1, 101)
	singe_ans = sum(lst)**2
	double_ans = sum([i**2 for i in lst])
	print singe_ans - double_ans
