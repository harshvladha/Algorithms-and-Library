t=int(input())
a=[]
while(t>0):
    n=int(raw_input())
    n-=1
    k = (n//3)*(6+3*((n//3)-1))
    k += (n//5)*(10+5*((n//5)-1))
    k -= (n//15)*(30+15*((n//15)-1))
    print(int(k/2))
    t-=1