import sys
import math

def Choose(n, k):
    if(k==1):
        return n
    else:
        return round((n/k)*Choose(n-1, k-1))

n, k = map(int, input().split())

print(Choose(n, k))
