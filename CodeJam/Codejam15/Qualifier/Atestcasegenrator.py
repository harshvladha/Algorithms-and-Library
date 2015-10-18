from random import randint
f = open('samplei.txt', 'w')
T = "100"
string = T+"\n"
f.write(string)
for t in range(int(T)):
    n = randint(5,1000)
    n0 = n+1
    n1 = 10**(n0-1)
    n2 = 10**(n0)-1
    s = randint(n1,n2)
    n = str(n)
    s = str(s)
    string = n+" "+s+"\n"
    f.write(string)
f.close()
