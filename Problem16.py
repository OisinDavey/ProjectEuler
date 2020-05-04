import sys
import math

def binpow(base, expo):
    if expo == 0:
        return 1
    elif expo == 1:
        return base
    else:
        temp = binpow(base, expo//2)
        if expo % 2:
            return temp*temp*base
        else:
            return temp*temp

a = str(binpow(2, 1000))

sumn = 0

for c in a:
    sumn += int(c)

print(sumn)
