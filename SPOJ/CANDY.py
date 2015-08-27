import sys,math

def getints():
	return map(int, raw_input().strip().split())

while(1):
	t = input()
	if t == -1:
		break
	s = 0
	a = []
	for i in range(t):
		i = input()
		a.append(i)
		s+=i
	if s%t != 0 :
		print -1
	else:
		e = s/t
		o = 0
		for b in a:
			if b > e:
				o += b-e
		print o