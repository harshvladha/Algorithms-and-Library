def cleaninput():
	return raw_input().strip()

if __name__ == '__main__':
	s = cleaninput()
	l = len(s)
	ways = 0
	for i in xrange(l, 1, -1):
		ways+=i
	prev = None
	rep = {}
	for k in s:
		if prev != None and k == prev:
			rep[k]+=1
		else:
			rep[k]=1
			prev = k
	similar = 1
	for i in rep:
		similar = similar*rep[i]

	print similar, ways