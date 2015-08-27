import sys
def getints():
	return map(int, raw_input().strip().split())

#build dictionary
quaternions = {'1':{'1':'1','i':'i','j':'j','k':'k'},'i':{'1':'i','i':'-1','j':'k','k':'-j'},'j':{'1':'j','i':'-k','j':'-1','k':'i'},'k':{'1':'k','i':'j','j':'-i','k':'-1'}}
matchstr = ['i','j','k']
def get(x,y):
	nf = False
	if len(x)>1 and len(y)>1:
		x = x[1]
		y = y[1]
	elif len(x)>1 and len(y)==1:
		x = x[1]
		nf = True
	elif len(x)==1 and len(y)>1:
		y = y[1]
		nf = True

	if nf==False:
		temp = quaternions[x][y]
	else:
		if len(quaternions[x][y])>1:
			temp = quaternions[x][y][1]
		else:
			temp = '-'+quaternions[x][y]

	return temp

t = int(raw_input())
for _ in xrange(t):
	l,x = getints()
	s = raw_input().strip()
	fs = s*x
	l1 = l*x
	if l == 1:
		ans = "NO"
	elif l1 < 3:
		ans = "NO"
	else:
		i = 1
		flag = 0
		current = fs[0]
		while i < l1:
			while current != matchstr[flag] and i<l1:
				current = get(current,fs[i])
				i+=1
			if flag<2  and current==matchstr[flag]:
				flag+=1
			elif flag==2 and i==l1-1 and current==matchstr[flag]:
				flag+=1
			i+=1
			current = fs[i]
		if flag==3:
			ans = "YES"
		else:
			ans = "NO"

	print "Case #{0}: {1}".format((_+1),ans)