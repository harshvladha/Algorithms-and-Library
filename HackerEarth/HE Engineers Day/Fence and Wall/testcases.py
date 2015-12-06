from random import randint
f = open('5i.txt', 'w')
T = str(randint(100000,600000))
L = 100
for t in range(int(T)):
    n = str(randint(1,L))
    string = n+"\n"
    f.write(string)
f.write("0")
f.close()
