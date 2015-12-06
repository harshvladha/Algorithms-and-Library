from random import randint
f = open('5i.txt', 'w')
T = str(randint(10000,10000))
f.write(T+"\n")
N = 10**9
for t in range(int(T)):
    n = str(randint(1,N))
    string = n+"\n"
    f.write(string)
f.close()
