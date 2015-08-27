import sys,math

myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getints():
	return map(int, cleaninput().split())

def getfloats():
	return map(float, cleaninput().split())

def main():
	while True:
		g,b = getfloats()
		if int(g) == -1 or int(b) == -1:
			break;
		elif g == b and g != 0:
			print 1;
		elif g == 0 or b == 0 :
			if g:
				print int(g)
			else:
				print int(b)
		elif g == 0 and b == 0:
			print 0
		elif g > b:
			print int(math.ceil(g/(b+1)))
		elif b > g:
			print int(math.ceil(b/(g+1)))

if __name__ == '__main__':
	main()