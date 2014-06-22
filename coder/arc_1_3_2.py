import sys
def main():
    ans = []
    for i in range(8):
        ans.append(raw_input())
    dp(0, ans)
    print "No Answer"

def check(x, y, lst):
    def _check(x, y, f):
        if x > 7 or y > 7 or x < 0 or y < 0:
            return True
        elif lst[x][y] == 'Q':
            return False
        elif f == 0:
            return _check(x-1, y-1, 0)
        elif f == 1:
            return _check(x-1, y+1, 1)
        elif f == 2:
            return  _check(x+1, y-1, 2)
        elif f == 3:
            return _check(x-1, y-1, 3)
    if 'Q' in lst[x][:y] or 'Q' in lst[x][y+1:]:
        return False
    for i in xrange(8):
        if i == x: pass
        elif lst[i][y] == 'Q': return False
    else:
        return _check(x-1, y-1, 0) and _check(x-1, y+1, 1) and\
            _check(x+1, y-1, 2) and _check(x-1, y-1, 3)

def dp(n, lst):
    if n > 7:
        for i in lst:
            print i
        sys.exit()
    else:
        for j in xrange(8):
            if check(n, j, lst):
                clst = lst[:]
                clst[n] = lst[n][:j] + 'Q' + lst[n][j+1:]
                dp(n+1, clst)
main()
