from math import factorial
def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

for _ in xrange(getint()):
	n, k = getints()
	ans = factorial(n-1)/(factorial(n-k)*factorial(k-1))
	print ans