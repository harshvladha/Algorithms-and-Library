t = input()
for _ in range(t):
	s,si = raw_input().strip().split()
	s = int(s)
	ans = 0
	total = 0
	for i in range(s+1):
		if total>=i or si[i]=='0':
			total+=int(si[i])
		else:
			temp = i-total
			total+=temp+int(si[i])
			ans+=temp
	print "Case #{0}: {1}".format((_+1),ans)
