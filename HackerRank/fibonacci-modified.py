import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

def main():
	a,b,n = getints()
	c = 0
	for _ in range(n-2):
		c = b**2 + a
		a = b
		b = c
	print c

if __name__ == '__main__':
	main()