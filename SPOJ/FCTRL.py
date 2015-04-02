t = input()
for i in range(t):
	n = input()
	x = 5
	ans = 0
	while(x<=n):
		ans += n/x
		x*=5
	print ans
