import sys
while(1):
	c = input()
	if c==0:
		break
	s = raw_input().strip()
	c1 = (2*c)+1
	c2 = -1
	for i in range(c):
		sys.stdout.write(s[i])
		j=i
		flag=0
		c1-=2
		c2+=2
		while(1):
			if flag==0:
				j+=c1
				flag=1
				if j>(len(s)-1):
					break
			elif flag==1:
				j+=c2
				flag=0
				if j>(len(s)-1):
					break
			sys.stdout.write(s[j])
	print 
