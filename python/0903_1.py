def min(*args):
    res = args[0]
    for arg in args[1:]:
        if arg < res:
            res = arg
    return res
