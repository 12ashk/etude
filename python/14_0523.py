#! /usr/bin/env python3
# -*- coding: utf-8 -*-
import random

class genetic_algorithm(object):
    def __init__(self):
        self.alphabets = list(map(chr, range(ord('A'), ord('Z')+1)))
        self.num = 50
        self.length = 8
        self.ans = 'ILOVEYOU'
        self.threshold = int(self.num/2)
        self.mutprob = 0.2
        self.crossprob = 0.5

        self.array = []
        for i in range(self.num):
            self.array.append(''.join(map(str, 
                        (random.choice(self.alphabets) for j in range(self.length))))+'0')

    def count_match(self, a):
        return str(sum([1 for i in range(self.length) if a[i] == self.ans[i]]))

    def calc_fitness(self):
        for i in range(self.num):
            self.array[i] = self.array[i][:-1] + self.count_match(self.array[i])
        self.array = sorted(self.array, key=lambda s: s[-1], reverse=True)
            
    def cross_over(self, a, b):
        i, j = 0, 0
        while(i != j):
            i = self.randlen()
            j = self.randlen()
        i, j = min(i, j), max(i, j)
        return a[:i] + b[i:j] + a[j:]

    def mutation(self, a):
        i = self.randlen()
        a = a[:i] + random.choice(self.alphabets) + a[i+1:]
        return a

    def randnum(self):
        return random.randint(0, self.num-1)

    def randlen(self):
        return random.randint(0, self.length-1)

    def main(self):
        c = 0
        while(self.array[0][:-1] != self.ans):
            self.calc_fitness()
            ngen = self.array[:self.threshold]
            i = self.threshold
            while i < self.num:
                if random.random() < self.crossprob:
                    ngen.append(self.cross_over(self.array[self.randnum()], self.array[self.randlen()]))
                    i+=1
                if random.random() < self.mutprob and i < self.num:
                    ngen.append(self.mutation(self.array[self.randnum()]))
                    i+=1
                ngen.append(self.array[self.randnum()])
                i+=1
            self.array = ngen
            c += 1
        return c

def main():
    gene = genetic_algorithm()
    print(gene.main())

if __name__ == '__main__':
    main()
