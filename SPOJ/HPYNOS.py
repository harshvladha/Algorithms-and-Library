n = int(raw_input())
flag = 1
l = []
while True:
	ans = 0
	while n > 0:
		ans += (n%10)**2
		n /= 10
	if ans == 1:
		break
	n = ans

	if ans in l:
		flag = 0
		break
	else:
		l.append(ans)

if flag == 0:
	print -1
else:
	print len(l) + 1
