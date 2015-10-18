t = int(input())
for i in range(t):
    n = int(input())
    a=1
    b=2
    s=2
    c=a+b
    while(c<=n):
        if(c%2==0):
            s+=c
        a=b
        b=c
        c=a+b
    print(s)