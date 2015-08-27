import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())


def getmax(n):
	if n == 0:
		return 0
	try:
		ans = a[n]
	except KeyError:
		ans = 0
	if ans == 0:
		b = max(n, getmax(n/2)+getmax(n/3)+getmax(n/4))
		a[n] = b
	return a[n]
def main():
	while True:
		try:
			t = getint()
			print getmax(t)
		except:
			break


if __name__ == '__main__':
	a = {}
	main()