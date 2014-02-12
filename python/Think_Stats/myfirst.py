#! /usr/bin/env Python
#! -*- utf-8 -*-

import survey
import math

def get_prgdata():
    table = survey.Pregnancies()
    table.ReadRecords()
    return table

def get_prglist(t):
    first = []
    other = []

    for i in t.records:
        if i.outcome == 1:
            if i.birthord == 1:
                first.append(float(i.prglength))
            else:
                other.append(float(i.prglength))

    return first, other


def get_mean(t):
    return float(sum(t) / len(t))

def get_var(t, mean):
    var = 0.0
    
    for i in t:
        var += (i - mean) ** 2
    var /= float(len(t))

    return var

def main():
    table = get_prgdata()
    first, other = get_prglist(table)
    f_mean = get_mean(first)
    o_mean = get_mean(other)
    f_var = get_var(first, f_mean)
    o_var = get_var(other, o_mean)
    f_std_dev = math.sqrt(f_var)
    o_std_dev = math.sqrt(o_var)

    print 'variance of first babies: %f\nvariance of others: %f'\
              %  (f_std_dev, o_std_dev)

if __name__ == '__main__':
    main()
