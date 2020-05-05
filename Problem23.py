import sys
import math
from bisect import bisect_left

abundant = []

def BinarySearch(a, x): 
    i = bisect_left(a, x) 
    if i != len(a) and a[i] == x: 
        return i 
    else: 
        return -1

def SumOfProperFactors(n):
    S = math.sqrt(n)
    i = 2
    count = 1
    while(i <= S):
        if(i == S):
            count += i
        elif(n%i==0):
            count += i
            count += n/i
        i += 1
    return count

def FillAbundant():
    for i in range(1, 28124):
        if SumOfProperFactors(i) > i:
            abundant.append(i)

FillAbundant()

def CanBeWritten(n):
    B = False
    for x in abundant:
        if x > n:
            break
        if BinarySearch(abundant, n-x) != -1:
            B = True
            break
    return B

count = 0

for i in range(1, 28124):
    if CanBeWritten(i) == False:
        count += i

print(count)
