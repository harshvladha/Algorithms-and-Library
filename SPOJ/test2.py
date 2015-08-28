def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

if __name__ == '__main__':
	for _ in xrange(getint()):
		n = getint()
		tastes = getints()
		l = len(tastes)
		myl = []
		for i in xrange(0,l-2, 3):
			a = tastes[i]
			b = tastes[i+1]
			c = tastes[i+2]

			s1 = abs(a-b)
			s2 = abs(a-c)
			s3 = abs(b-c)
			bigg = max(s1,s2,s3)
			small = min(s1,s2,s3)
			midd = s1+s2+s3 - bigg - small
			myl.append(midd)
			myl.append(bigg)

		myl.sort()
		ans = 0
		for i in xrange(len(myl)):
			ans += (i+2)*myl[i]

		print ans