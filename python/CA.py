#! /usr/bin/env python
# -*- coding: utf-8 -*-

# 1 dimensional cellular automaton

def dec2bin(n):
    bit_list = []
    for i in range(8):
        bit_list.append(n % 2)
        n /= 2
    return bit_list

def ca(width, height, rulenum):
    results = []

    first_row = [0] * width
    first_row[width/2] = 1
    results.append(first_row)

    rule = dec2bin(rulenum)

    for i in range(height - 1):
        old_row = results[-1]
        new_row = []
        for j in range(width):
            n = 4 * old_row[(j-1)%width] + 2 * old_row[j] + old_row[(j+1)%width]
            new_row.append(rule[n])
        results.append(new_row)
    return results

def render(results, width, height):
    for y in range(height):
        for x in range(width):
            if results[y][x] == 1:
                print '__', 
            else:
                print '**',
        print

if __name__ == '__main__':
    width, height = 40, 30 
    rulenum = input('input rule number: ')
    results = ca(width, height, rulenum)
    render(results, width, height)
