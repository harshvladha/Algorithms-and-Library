def getints():
	return map(float, raw_input().strip().split())
while(1):
	a,b,c = getints()
	if a==b and b==c and a==0:
		break
	if 2*b == a+c :
		d = int(2*c-b)
		print "AP {0}".format(d)
	else:
		d = c * float(c/b)
		print "GP {0}".format(int(d))
