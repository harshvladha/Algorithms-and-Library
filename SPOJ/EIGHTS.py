import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

def solve(n):
	ans = 192
	if n == 1:
		return ans
	else:
		ans+=(n-1)*250
		return ans


def main():
	for _ in xrange(getint()):
		k = getint()
		print solve(k)


if __name__ == '__main__':
	#a = {}
	main()