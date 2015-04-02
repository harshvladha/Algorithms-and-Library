def getints():
	return map(int, raw_input().strip().split())

t = input()

for i in range(t):
	x, y = getints()
	if x == y :
		num = 0
		if x%2 == 0 :
			num = 4 + (x/2 - 1)*4
		else:
			num = 1 + (x-x/2 - 1)*4
		print num
	elif x-y==2 :
		num = 0
		if x%2 == 0 :
			num = 2 + (x/2 - 1)*4
		else:
			num = -1 + (x-x/2 - 1)*4
		print num
	else:
		print "No Number"
