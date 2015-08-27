import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def main():
	while True:
		N = getint()
		if N == -1:
			break
		#check for any n, whether 3n(n-1) + 1 = N
		if N%2:
			N-=1
			if N%3 == 0:
				N /= 3
				N = N*4 + 1
				a = int(math.sqrt(N))
				if a*a == N:
					if a%2:
						print "Y"
					else:
						print "N"
				else:
					print "N"
			else:
				print "N"
		else:
			print "N"


if __name__ == '__main__':
	main()