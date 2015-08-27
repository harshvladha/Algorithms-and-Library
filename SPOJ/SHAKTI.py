import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

def main():
	t = getint()
	for i in range(t):
		n = getint()
		if n%2 == 0 :
			print "Thankyou Shaktiman"
		else:
			print "Sorry Shaktiman"

if __name__ == '__main__':
	main()