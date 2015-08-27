import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getints():
	return map(int, cleaninput().split())

def main():
	while True:
		a,d = getints()
		if a==0 or d==0:
			break
		aa = getints()
		ad = getints()
		
		aa.sort()
		ad.sort()

		if aa[0] < ad[1]:
			print "Y"
		else:
			print "N"
if __name__ == '__main__':
	main()