#! /usr/bin/env Pythin
#! -*- utf-8 -*-

import thinkstats
import math

def Variance(t):
    var = 0
    mean = thinkstats.Mean(t)

    for i in t:
        var += (i - mean) ** 2

    var /= len(t)
    std_dev = math.sqrt(var)
    return var, std_dev

def main():
    P = [0.5, 1.5, 96]
    print 'mean: %.1f' % (thinkstats.Mean(P))
    print 'variance: %.1f\nstandard deviation: %.1f' % (Variance(P))

if __name__ == '__main__':
    main()
