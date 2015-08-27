import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

def main():
	for _ in range(getint()):
		x, y, z = getints()

		n = (2*z)/(x+y)
		d = (y-x)/(n-5)
		a = x - 2*d

		print n

		for i in range(n):
			if i > 0:
				myprint(" ")
			num = a + i*d
			myprint(str(num))
		print
if __name__ == '__main__':
	main()