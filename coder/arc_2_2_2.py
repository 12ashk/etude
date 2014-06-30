import datetime
def check(date):
    y, m, d = date.year, date.month, date.day
    if y/float(m) % d == 0:
        print "%d/%02d/%02d" % (y, m, d)
        return True
    return False
y, m, d = map(int, raw_input().split('/'))
date = datetime.date(y, m, d)
while not check(date):
    date += datetime.timedelta(1)
