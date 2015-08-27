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

def main():
	for _ in range(getint()):
		a = getints()
		b = getints()
		b.sort(reverse=True)
		ans = 0
		total = 0
		for i in b:
			if total < a[0]:
				total+=i
				ans+=1
		if ans==a[1] and total<a[0]:
			ans="impossible"
		print "Scenario #{0}:\n{1}\n".format((_+1),ans)

if __name__ == '__main__':
	main()