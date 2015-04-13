def getlargest(s,i,j,p,q):
    largest = 0
    unmatched = 0
    l = 0
    while i+l < len(p) and j+l < len(p):
        if p[i+l]!=q[j+l]:
            unmatched+=1
        if unmatched > s:
            largest = max(largest,l)
            while p[i]==q[j]:
                i+=1
                j+=1
                l-=1
            unmatched-=1
            i+=1
            j+=1
        else:
            l+=1
    return max(largest,l)

def solve(s,p,q):
    l = len(p)
    largest = 0
    for i in xrange(l):
        largest = max(largest, getlargest(s,0,i,p,q), getlargest(s,i,0,p,q))
    print largest

def main():
    for _ in xrange(input()):
        s,p,q = raw_input().strip().split()
        s = int(s)
        solve(s,p,q)


if __name__ == "__main__":
    main()
