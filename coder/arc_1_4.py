import math
def calc_distance(x1, y1, x2, y2):
    return math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))

N = input()
start, goal = map(int, raw_input().split())
ans = [[0, start]]
j = 0
for i in xrange(1, N+1):
    t = map(int, raw_input().split())
    d = float(goal-ans[j][1])/(N-ans[j][0])
    p = ans[j][1]+(i-ans[j][0])*d/(N-ans[j][0])
    if p < t[0]:
        j+=1
        ans.append([i, t[0]])
    if t[1] < p:
        j+=1
        ans.append([i, t[1]])
    else:
        dx1 = float(t[0]-ans[j][1])/(i-ans[j][0])
        dx2 = float(t[1]-ans[j][1])/(i-ans[j][0])

dist = 0
for i in xrange(len(ans)-1):
    dist += calc_distance(ans[i][0], ans[i][1], ans[i+1][0], ans[i+1][1])
print dist + calc_distance(ans[-1][0], ans[-1][1], N, goal)
