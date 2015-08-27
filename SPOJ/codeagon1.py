def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

if __name__ == '__main__':
	n, m = getints()
	count = 0
	while m>0 and n>0:
		count+=1
		m = m-n
		n-=1
	if n==0 and m>0:
		print -1
	else:
		print count