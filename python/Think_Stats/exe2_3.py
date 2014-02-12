#! /usr/bin/env Python
#! -*- utf-8 -*-

import Pmf
import sys
from operator import itemgetter

def get_hist(n):
    hist = Pmf.MakeHistFromList(n)
    return hist

def get_mode(n):
    hist = get_hist(n)
    histlist = hist.Items()
    mode = sorted(histlist, key = itemgetter(1), reverse = True)
    return mode

def main():
    varlist = []
    for i in range(5):
        varlist.append(input())

    mode = get_mode(varlist)
    for i in range(len(mode)):
       print 'mode: %d freqency: %d' % (mode[i][0], mode[i][1])

if __name__ == '__main__':
    main()
