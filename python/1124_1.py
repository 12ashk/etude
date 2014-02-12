#! /usr/bin/emv python
#! -*- utf-8 -*-

import sys


decimal_literal = int(sys.argv[1])

class DecimalNumber:
    def __init__(self, dec):
        self.dec = dec
        self.result = []

    def __to_binary(self):
        half = self.dec / 2
        residue = self.dec % 2
        if self.dec > 0:
            self.result.append(residue)
            self.dec = half
            self.__to_binary()

    def to_binary(self):
        """@return string"""
        self.__to_binary()
        s = ""
        self.result.reverse()
        for x in self.result:
            s += str(x)
        return s

DN = DecimalNumber(decimal_literal)
print "decimal: %d\n binarl: %s" % (decimal_literal, DN.to_binary())
