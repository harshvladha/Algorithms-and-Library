n = input()
ans = n
m = n/2
for i in range(2,m+1):
	for j in range(2, i+1):
		if i*j <= n:
			ans+=1
		else:
			break
print ans
