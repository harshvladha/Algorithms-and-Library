def reverse(n):
	n = str(n)
	n = n[::-1]
	return int(n)

t = int(raw_input())
for _ in range(t):
	n = int(raw_input())
	if n <=11:
		ans=n
	else:
		i = n
		ans = 11
		count = 0
		while i >= 12:
			count+=1
			#print i
			r = reverse(i)
			if r < n and r < i:
				i = r
			else : i-=1
		ans+=count
	print "Case #{0}: {1}".format((_+1),ans)