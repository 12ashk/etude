#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def hello(name):
    if name == 'Alice' or name == 'Nick':
        print 'Alert: Alice Mode'
        name = name + '???'
    else:
        Doesnotexit(name)# when name is Alice or Nick, it doesn't error
    name = name + '!!!!'
    print 'Hello', name
def main():
    hello(sys.argv[1])

if __name__ == '__main__':
    main()
