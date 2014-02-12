#/usr/bin/python -tt
# -*- coding: utf-8 -*-

import sys
import os

def list(dir):
    filenames = os.listdir(dir)
    print filenames
    for filename in filenames:
        path = os.path.join(dir, filename)
        print path
        print os.path.abspath(path)

def main():
    list(sys.argv[1])

if __name__ == '__main__':
    main()
