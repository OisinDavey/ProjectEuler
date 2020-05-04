import sys
import math

a = ""

for i in range(0, 20):
    a += input()

curnum = 1

numzeroes = 0

for i in range(0, 13):
    if numzeroes == 0:
        curnum *= int(a[i])
    else:
        curnum = 1

    if a[i] == "0":
        numzeroes += 1

maxx = curnum

l = 0
r = 13

while r < 1000:
    if a[l] != "0":
        curnum /= int(a[l])
    
    if a[r] != "0":
        curnum *= int(a[r])

    if a[r] == "0":
        numzeroes += 1
    if a[l] == "0":
        numzeroes -= 1

    if numzeroes == 0:
        maxx = max(maxx, curnum)
    
    l += 1
    r += 1

    print(curnum)

print(maxx)
