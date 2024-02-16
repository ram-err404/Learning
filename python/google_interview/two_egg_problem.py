import sys


def dropEgg(n, k):
    if(k == 1 or k == 0):
        return k
    if(n == 1):
        return k
    min = sys.maxsize
    for x in range(1, k+1):
        res = max(dropEgg(n-1, x-1), dropEgg(n, k-x))
        if(res < min):
            min = res
    return min + 1


def __main__():
    n = 2
    k = int(input("Enter number floors: "))
    print("Min number of floors required ", dropEgg(n, k))


__main__()
