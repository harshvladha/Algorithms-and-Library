def expmo(a, b):
	ans = 1
	while b:
		if b%2 :
			ans = (ans*a)%10
		b>>=1
		a=(a*a)%10
	return ans

for _ in range(input()):
	a = map(int, raw_input().strip().split())
	print expmo(a[0],a[1])
