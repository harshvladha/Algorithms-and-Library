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

def solve(n):
	ans = 0.00
	count = 0
	while ans < n:
		count+=1
		ans+=float(1)/float(count+1)
	return count

def main():
	while True:
		t = getfloat()
		if t == 0.00:
			break
		else:
			print "{0} card(s)".format(solve(t))


if __name__ == '__main__':
	main()