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
		cleaninput()
		g,m = getints()
		sg = getints()
		sm = getints()
		sg.sort(reverse=True)
		sm.sort(reverse=True)
		if sg[0] >= sm[0]:
			print "Godzilla"
		elif sg[0] < sm[0]:
			print "MechaGodzilla"  
		else:
			print "uncertain"



if __name__ == '__main__':
	main()