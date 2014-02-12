#! /usr/bin/env python
# -*- coding: utf-8 -*-

def my_last(x):
    return x[-1:]

def my_but_last(x):
    return x[-2:]

def element_at(x, k):
    return x[k-1]

def my_len(x, l):
    if x == []:
        return l
    else:
        return my_len(x[1:], l+1)

def my_reverse(x):
    if len(x) == 1:
        return x
    else:
        return my_reverse(x[1:]) + [x[0]]

def is_palidrome(x):
    for i in range(len(x)):
        if i >= len(x)-i-1:
            return True
        if x[i] != x[-(i+1)]:
            return False

def my_flatten(x):
    if len(x) == 1:
        return [x[0]]
    elif len(x[0]) == 1 and not isinstance(x[0], list):
        return [x[0]] + my_flatten(x[1:])
    else:
        return my_flatten(x[0]) + my_flatten(x[1:])

def compress(x, pre):
    if len(x) == 0:
        return [pre]
    elif len(pre) == 0:
        return compress(x[1:], [x[0]])
    elif x[0] == pre[0]:
        return compress(x[1:], pre + [x[0]])
    else:
        return [pre] + compress(x[1:], [x[0]])

def encode(x):
    x = compress(x, [])
    y = []
    for i in range(len(x)):
        y.append([len(x[i]), x[i][0]])
    return y

def encode_modified(x):
    x = compress(x, [])
    y = []
    for i in range(len(x)):
        if len(x[i]) == 1:
            y.append(x[i][0])
        else:
            y.append([len(x[i]), x[i][0]])
    return y

def decode(x):
    x = encode_modified(x)
    y = []
    for i in range(len(x)):
        if len(x[i]) == 1:
            y.append(x[i][0])
        else:
            for j in range(len(x[i])):
                y.append(x[i][1])
    return y

def encode_direct(x):
    count = 0
    y = []
    for i in range(len(x)):
        count += 1
        if len(x) == 2:
            if x[0] == x[1]:
                y.append([count+1, x[0]])
                return y
            else:
                y.append([count, x[0]]) + x[1]
                return y
        elif x[0] == x[1]:
            x = x[1:]
        else:
            if count == 1:
                y.append(x[0])
                x = x[1:]
                count = 0
            else:
                y.append([count, x[0]])
                x = x[1:]
                count = 0

def dupli(x):
    if x == []:
        return []
    else:
        return [x[0]] + [x[0]] + Dupli(x[1:])

def repli(x, count):
    if x == []:
        return []
    else:
        temp = []
        for i in range(count):
            temp.append(x[0])
        return temp + repli(x[1:], count)

def drop_body(x, count, c):
    if x == []:
        return []
    elif c == count:
        return drop(x[1:], count)
    else:
        return [x[0]] + drop_body(x[1:], count, c+1)

def drop(x, count):
    if x == []:
        return x
    else:
        return drop_body(x, count, 1)

def split_list_body(x, y, count):
    if count == 0:
        return x, y
    else:
        return split_list_body(x+list(y[0]), y[1:], count-1)


def split_list(x, count):
    if len(x) < count:
        return 'ERORR'
    elif count == 0 or count == len(x):
        return x
    else:
        return split_list_body(list(x[0]), x[1:], count-1)

def my_slice(x, first, last):
    last = len(x) - last
    for i in range(1, first):
        x = x[1:]

    for i in range(last):
        x = x[:len(x)-1]
    return x

def rotate(x, num):
    x, y = split_list(x, num)
    return y + x

def my_remove(x, num):
    if num == 1:
        return x[1:]
    else:
        return [x[0]] + my_remove(x[1:], num-1)

def insert_at(a, x, num):
    if num == 1:
        return [a] + x
    else:
        return [x[0]] + insert_at(a, x[1:], num-1)

def my_range(x, y):
    if x == y:
        return [x]
    elif x < y:
        return [x] + my_range(x+1, y)
    else:
        return [x] + my_range(x-1, y)

def combination(lst, n):
	def comb(pre, after):
		if len(after) == 1:
			return []
		return [pre + [after[0]]] + comb(pre, after[1:])
	ans = []
	for i in xrange(len(lst)-n+1):
		ans += comb(lst[i:i+n-1], lst[i+n-1:])
	return ans
		
def main():
	print combination([1, 2, 3, 4, 5, 6], 3)

if __name__ == '__main__':
    main()
