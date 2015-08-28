from fractions import gcd
for _ in range(int(input().strip())):
	a,b = map(int, input().strip().split())
	print(gcd(a,b))

#FAILED the test cases as TLE