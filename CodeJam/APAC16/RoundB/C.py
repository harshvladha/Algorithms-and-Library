import math
def totalDigits(number):
	return int(math.floor(math.log10(abs(number))))+1

def checkPrime(x):
	if x==0 or x==1 or x==2 or x==3 or x==5 or x==7:
		return True
	return False

for _ in xrange(int(raw_input())):
	n = int(raw_input().strip())
	flag = 0
	count = 0
	for i in range(totalDigits(n)):
		p = n%10
		if checkPrime(p) == False:
			flag = 1
			count += 1
		n/=10
	if flag == 1 and count%2 == 1:
		print "Case #{0}: Laurence".format((_+1))
	else:
		print "Case #{0}: Seymour".format((_+1))