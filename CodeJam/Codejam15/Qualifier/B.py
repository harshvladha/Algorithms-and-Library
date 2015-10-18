def getints():
	return map(int, raw_input().strip().split())

t = int(raw_input())
for _ in xrange(t):
	d = int(raw_input())
	p = getints()
	maxi = max(p)
	ans = maxi
	for i in range(1,maxi+1):
		sums = i
		for j in range(d):
			if p[j] > i:
				if p[j]%i==0:
					sums+=(p[j]/i-1)
				else:
					sums+=(p[j]/i)
		ans = min(ans, sums)
	print "Case #{0}: {1}".format((_+1),ans)




