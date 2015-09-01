def NonContigous(a):
    ind = 0
    s=0
    for i in xrange(len(a)):
        if a[i] > 0:
            s+=a[i]
        else:
            if(a[i]>=a[ind]):
                ind = i
    if s!=0:
        return s
    else:
        return a[ind]
def Contigous(a):
    cs = 0 #current sum
    ci = -1 #current index
    bs = 0 #best sum 
    bsi = -1 #best starting index
    bei = -1 #best ending index
    ind = 0 #index
    for i in xrange(len(a)):
        v = cs + a[i]
        if v > 0:
            if cs == 0:
                ci = i
            cs = v
        else:
            cs = 0
        if a[i]<0:
            if(a[i]>=a[ind]):
                ind = i
        if cs > bs:
            bs = cs
            bsi = ci
            bei = i
    if bs!=0:
        return bs            
    else:
        return a[ind]
for i  in range(input()):
    input()
    ar = map(int, raw_input().strip().split())
    print Contigous(ar),
    print NonContigous(ar)