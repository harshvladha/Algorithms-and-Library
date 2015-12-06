f = open('10o.txt', 'w')
for i in xrange(input()):
    n,k = map(int,raw_input().strip().split())
    k = k+1
    answer = (k*(k-1))//2
    string = str(answer)+"\n"
    f.write(string)
f.close()
