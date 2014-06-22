def main():
    def search(t, c):
        if t == final:
            print c
        else:
            if t - final > 7:
                memo.append(t-10)
                search(t-10, c+1)
            elif t - final > 2:
                memo.append(t-5)
                search(t-5, c+1)
            elif t > final:
                memo.append(t-1)
                search(t-1, c+1)
            elif final - t > 7:
                memo.append(t+10)
                search(t+10, c+1)
            elif final - t > 2:
                memo.append(t+5)
                search(t+5, c+1)
            elif t < final:
                memo.append(t+1)
                search(t+1, c+1)
    init, final = map(int , raw_input().split())
    memo = [init]
    search(init, 0)
main()
