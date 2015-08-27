import sys,math
 
def getints():
	return map(int, raw_input().strip().split())
 
for _ in range(input()):
	n = input()
	m = getints()
	w = getints()
	m.sort()
	w.sort()
	s = 0
	for i in range(n):
		s+=m[i]*w[i]
	print s