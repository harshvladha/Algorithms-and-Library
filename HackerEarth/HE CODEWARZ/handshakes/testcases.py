from random import randint
for i in range(10):
    num = i+1
    t = num*100
    num = str(num)
    file =  num+'i.txt'
    f = open(file, 'w')
    T = str(randint(75,t))
    string = T+"\n"
    f.write(string)
    N = 1000000
    for t in range(int(T)):
        n = randint(0,N)
        k = str(randint(0,n))
        n = str(n)
        string = n+" "+k+"\n"
        f.write(string)
    f.close()
