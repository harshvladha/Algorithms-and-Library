def cleaninput():
	return raw_input().strip()

def getints():
	return map(int, cleaninput().split())

for _ in xrange(int(raw_input())):
	n, p = getints()

	if p == 0:
		print "Airborne wins."
	else:
		print "Pagfloyd wins."