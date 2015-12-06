from random import randint
f = open('6i.txt', 'w')
T = str(randint(20,25))
string = T+"\n"
f.write(string)
N = 30
for t in range(int(T)):
    n = str(randint(20,N))
    string = n+"\n"
    f.write(string)
f.close()
