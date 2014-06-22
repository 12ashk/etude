# does not work well
import sys
class main():
    def printans(self):
        for i in xrange(8):
            for j in xrange(8):
                if self.ans[i] == j:
                    sys.stdout.write('Q')
                else:
                    sys.stdout.write('.')
            print 

    def input_init(self):
        self.lst = []
        for i in xrange(8):
            t = raw_input()
            for j in xrange(8):
                if t[j] == 'Q':
                    if len(self.lst) > i:
                        self.flag = False
                        break
                    self.lst.append(j)
            if len(self.lst) < i+1:
                self.lst.append(None)

    def check(self, n, m):
        if m in self.ans[:n] or m in self.ans[n+1:]:
            return False
        i = 1
        while min(n, m) - i >= 0:
            if self.ans[n-i] == m-i:
                return False
            i+=1
        i = 1
        while n - i >= 0 and m + i < 8:
            if self.ans[n-i] == m+i:
                return False
            i+=1
        i = 1
        while m - i >= 0 and n + i < 8:
            if self.ans[n+i] == m-i:
                return False
            i+=1
        i = 1
        while max(n, m) + i < 8:
            if self.ans[n+i] == m+i:
                return False
            i+=1
        return True

    def dp(self, n):
        if self.flag == True:
            return True
        if n > 7:
            self.printans()
            self.flag = True
            return True
        elif self.lst[n]:
            self.dp(n+1)
        else:
            for i in xrange(8):
                if self.check(n, i):
                    self.ans[n] = i
                    self.dp(n+1)
                    self.ans[n:] = self.lst[n:]

    def __init__(self):
        self.flag = True
        self.input_init()
        self.ans = self.lst[:]
        for i in xrange(8):
            if self.lst[i]:
                if not self.check(i, self.lst[i]):
                    self.flag = False
        if self.flag == True:
            self.flag = False
            self.dp(0)
        if self.flag == False:
            print "No Answer"
main()
