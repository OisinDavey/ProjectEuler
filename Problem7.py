import sys
import math

prime_list = [2, 3]

curnum = 5

while(len(prime_list) < 10001):
    B = True
    for x in prime_list:
        if curnum % x == 0:
            B = False
            break
    if B:
        prime_list.append(curnum)
    curnum += 2

print(prime_list[len(prime_list)-1])
