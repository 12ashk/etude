#! /usr/bin/python -tt
#! -*- coding: utf-8 -*-

def donuts(count):
    return 'Number of donuts: ' + count

def both_ends(s):
    if len(s) <= 2:
        return []
    else:
        return s[:2] + s[-2:]

def fix_start(s):
    first = s[0]
    back = s[1:]
    return s[0] + back.replace(first, '*')

def return_text():
    return 'text'
import sys

def for_check(words):
    for word in words:
        print word
def sort_check(words):
    sorted(words, key=lambda x: x[-1])
    print words

if __name__ == '__main__':
    sort_check(['123', '321', '456'])


