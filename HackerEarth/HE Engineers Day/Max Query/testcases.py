from random import randint
f = open('5i.txt', 'w')
T = str(randint(10000,10000))
f.write(T+"\n")
N = 900500
for t in range(int(T)):
    n = str(randint(10000,N))
    string = n+" "
    f.write(string)
f.write("\n")
Q = str(randint(10000,10000))
f.write(Q+"\n")
for t in range(int(Q)):
    n = str(randint(0,int(T)-1))
    m = str(randint(int(n),int(T)-1))
    string = n+" "+m+"\n"
    f.write(string)
f.close()
