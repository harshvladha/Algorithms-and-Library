t = input()
for _ in range(t):
    s = raw_input()
    l = len(s)
    s = list(s)
    flag = 0
    ind = -1
    for i in range(l-1,0,-1):
        if ord(s[i]) > ord(s[i-1]): # first place where left digit is less than the right digit
            ind = i-1
            flag = 1
            break
    if flag == 1:
        greateri = ind+1
        for i in range(ind+2, l):
            greater = ord(s[greateri])
            if ord(s[i]) > ord(s[ind]) and ord(s[i]) < greater: # mark the "just" higher number index
                greateri = i
        s[greateri],s[ind] = s[ind],s[greateri] # swap the two marked numbers
        s = ''.join(s[:ind+1]+sorted(s[ind+1:])) # sort thereafter and make it a string
        print s # print it 
    else:
        print 'no answer'