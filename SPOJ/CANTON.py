import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

def getfloat():
	return float(cleaninput())

def getfloats():
	return map(float, cleaninput().split())

def main():
	for _ in xrange(getint()):
		a = getint()
		i = 1
		while i*(i+1) < 2*a:
			i+=1

		t=i-1
		tt = t*(t+1) / 2
		s = a - tt - 1
		if i%2 == 0 :
			n = 1+s
			d = i-s
		else:
			n = i-s
			d = 1+s
		print "TERM {0} IS {1}/{2}".format(a,n,d)



if __name__ == '__main__':
	main()