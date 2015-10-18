def get(n):
	if n%4 == 0:
		return 0
	elif n%4 == 2:
		return 1
	elif n%2 == 1:
		return get(n/2)

for _ in range(int(raw_input())):
	n = int(raw_input())
	print "Case #{0}: {1}".format((_+1),get(n-1))

