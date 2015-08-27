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
	while True:
		n = getint()
		if n==0:
			break
		nos = getints()

		ip = []

		for i in xrange(n):
			ip.append(0)
		for i in xrange(n):
			ip[nos[i]-1] = i+1
		if nos == ip:
			print "ambiguous"
		else:
			print "not ambiguous"

if __name__ == '__main__':
	main()