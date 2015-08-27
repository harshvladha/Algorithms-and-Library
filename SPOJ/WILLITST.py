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
	t = getint()
	k = int(math.log(t,2))
	if 2**k == t or t<=1:
		print "TAK"
	else:
		print "NIE"

if __name__ == '__main__':
	main()