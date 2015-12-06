#f = open('6o.txt', 'w')
from fractions import gcd
import math

def theR(n):
    if n == 1 or n == 2 or n==1 :
        return 1;
    if n==3 or n==4:
        return 3
    if n==5 or n==6:
        return 3*5
    if n>=7 and n <=10:
        return 3*5*7
    if n>10:
        n = float(n)
        f = math.ceil(n/4)
        five = math.ceil(n/5)
        ten = math.ceil(n/10)
        return 2**f * theR(five) * theR(ten)
def calc(x,y):
    return (x**y) % (1000000007)
T = int(input())
for t in range(T):

    n = int(raw_input().strip())
    R = int(theR(n))
    print R
    maximum = 0
    for x in range(R,R*6,R):
        for y in range(R,R*6,R):
            z = calc(x,y)
            #print x,y,z
            if z > maximum:
                maximum = z
    string = str(maximum)+"\n"
    #f.write(string)
