import sys
import math

NUMs = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]

TEEs = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]

TENs = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

def digitCount(n):
    if(len(n) == 0):
        return ""
    elif(len(n) == 1):
        return NUMs[int(n)]
    elif(len(n) == 2):
        if(n[0] == "1"):
            return TEEs[int(n[1])]
        else:
            return TENs[int(n[0])] + " " + NUMs[int(n[1])]
    elif(len(n) == 3):
        temp = digitCount(str(int(n[1:3])))
        if(temp == ""):
            return NUMs[int(n[0])] + " hundred"    
        else:
            return NUMs[int(n[0])] + " hundred and " + temp 
    elif(len(n) == 4):
        return NUMs[int(n[0])] + " thousand " + digitCount(str(int(n[1:3])))

count = 0

n = int(input())

for i in range(1, n):
    temp = digitCount(str(i))
    for c in temp:
        if c != " ":
            count += 1

print(count)

#print(digitCount(str(100)))
