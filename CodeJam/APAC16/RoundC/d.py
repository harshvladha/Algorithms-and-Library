import sys,math
from operator import itemgetter
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

if __name__ == '__main__':
	t = getint()
	for _ in xrange(t):
		n,k,c,x = getints()
		a = getints()
		b = getints()
		ans = 0
		L = 0
		K = 0
		while(L <= n-k+1):
			L+=1
			last = 0
			while(K <= n-k+1):
				K+=1
				i = L
				j = K
				coun_i = 0
				while(coun_i < k):
					i += coun_i
					coun_j = 0
					while(coun_j < k):
						j += coun_j
						print i,j
						curr = (i*a[i-1]+j*b[j-1]+c)%x
						#print curr
						last = max(curr,last)
						coun_j += 1
					#print "term"
					coun_i += 1
				#print "termii"
				ans += last

		print "Case #{0}: {1}".format((_+1), ans)