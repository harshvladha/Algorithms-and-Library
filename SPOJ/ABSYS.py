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
		raw_input()
		a = raw_input().strip().split()
		try:
			x = int(a[0])
		except ValueError:
			x = -1
		try:
			y = int(a[2])
		except ValueError:
			y = -1
		try:
			z = int(a[4])
		except ValueError:
			z = -1

		if x == -1:
			x = z - y
		if y == -1:
			y = z - x
		if z == -1 :
			z = x+y
		print "{0} + {1} = {2}".format(x,y,z)


if __name__ == '__main__':
	main()