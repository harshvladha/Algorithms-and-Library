t = input()
for i in range(t):
	x,y = raw_input().strip().split()
	x = int(x[::-1])
	y = int(y[::-1])
	z = x+y
	z = str(z)
	print int(z[::-1])
