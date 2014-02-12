#! /usr/bin/env python
# -*- coding: utf-8 -*-

"""
Workers in a IT company named LiveGate
"""

class Workers:
    """ This is a class of workers working in the company """

    def __init__(self, name, position, email, age, salary):
        self.name = name
        self.position = position
        self.email = email
        self.age = age
        self.salary = salary

class ITWorkers(Workers):
    """ This is a class of IT engineers """

    OS = 'WinNT'

    def __init__(self, language, *rest):
        Workers.__init__(self, *rest)
        self.language = language

    def work(self, n):
        """ IT engineers should work """

        if self.position == 'web creator':
            w = 'makes web site'
        elif self.position == 'server administrator':
            w = 'check the trafic'
        elif self.position == 'programmer':
            w = 'write programs'

        print '%s %s for %d hours using %s on %s' \
                % (self.name, w, n, self.language, self.OS)

henley = ITWorkers('PHP', 'Hanley', 'web creator', \
        'henley@livegate.com',  32, 700)
thomas = ITWorkers('Python', 'Thomas', 'server administrator',\
        'thomas@',  37, 900)
gates = ITWorkers('C', 'Gates', 'programmer', 'gates@', 42, 1200)

henley.OS = 'Mac'
thomas.OS = 'Linux'

if __name__ == '__main__':
    henley.work(8)
    thomas.work(7)
    gates.work(10)
