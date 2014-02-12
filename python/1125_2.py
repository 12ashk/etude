#! /usr/bin/env python
# -*- coding: utf-8 -*-

"""
This code demonstrate how easy to imprement an object orienterd system
on a functional programing lauguage.

It only requires a nested hash table.
"""

def Cls(cls = None, **key):
    """making a new class"""
    key['class'] = cls
    return key

def new(cls, **key):
    """making an instance """
    key['class'] = cls
    return key

def geta(obj, attr):
    """getting the attribute of object """
    if attr in obj:
        return obj[attr]
    elif (obj['class']):
        return geta(obj['class'], attr)
    else:
        return None

def tell(obj, method, *av):
    """tell object do somethin"""
    fun = geta(obj, method)
    if callable(fun):
        return fun(obj, *av)

if __name__ == '__main__':
    def it_work(self, n):
        """This function demonstrates how IT engineers work.
           Notice that arguments of the function is identical to the method
           'work' in works.py"""
        if geta(self, 'position') == 'web creator':
            w = 'makes web sites'
        elif geta(self, 'position') == 'server administrator':
            w = 'checks the trafics'
        elif geta(self, 'position') == 'programmer':
            w = 'writes programs'

        print '%s %s for %d hours using %s on %s'\
        % (geta(self, 'name'), w, n, geta(self, 'language'), geta(self,'OS'))
    workers = Cls()
    it_workers = Cls(workers, OS='winNT', work=it_work)

    henley = new(it_workers, language = 'PHP', name = 'henley',\
    position = 'web creator', email = 'henley@', age = 32, salary = 700)

    henley['OS'] = 'Linux'

    tell(henley, 'work', 8)
