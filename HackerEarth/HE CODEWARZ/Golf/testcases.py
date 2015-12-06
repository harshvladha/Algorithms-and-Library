from random import randint
f = open('samplei.txt', 'w')
T = str(randint(10000,100000))
string = T+"\n"
f.write(string)
N = 10**16
for t in range(int(T)):
    n = str(randint(10,N))
    string = n+"\n"
    f.write(string)
f.close()
