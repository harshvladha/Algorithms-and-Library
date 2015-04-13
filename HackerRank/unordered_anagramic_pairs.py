def isAnagram(s1,s2):
    s1 = sorted(list(s1))
    s2 = sorted(list(s2))
    return s1==s2
def substrings(s):
    count = 0
    for size in range(1, len(s)+1):
        seen = []
        for index in range(len(s)+1-size):
            slc = s[index:index+size]
            seen.append(slc)
        for i in range(len(seen)):
            for j in range(i+1,len(seen)):
                #print seen[i], seen[j]
                if isAnagram(seen[i], seen[j]):
                    count+=1
    print count
t = input()
for _ in xrange(t):
    s = raw_input().strip()
    substrings(s)
