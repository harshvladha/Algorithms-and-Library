# n <= 10^16
# t <= 10000
from random import randint
f = open('1i.txt', 'w')
T = str(randint(1000,1000))
f.write(T+"\n")
N = 10**5
for t in range(int(T)):
    n = str(randint(10**3,N))
    string = n+"\n"
    f.write(string)
f.close()