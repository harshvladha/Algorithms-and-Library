import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def levDist(a, b):
	
	m = len(a)
	n = len(b)

	d  = [[0 for i in range(m+1)] for j in range(n+1)]

	for i in range(1,n+1):
		d[i][0] = i

	for i in range(1,m+1):
		d[0][i] = i

	for j in range(1, n+1):
		for i in range(1, m+1):
			if a[i-1] == b[j-1]:
				d[j][i] = d[j-1][i-1]
			else:
				d[j][i] = min(d[j-1][i]+1 , d[j][i-1]+1, d[j-1][i-1]+1)

	return d[n][m]

def main():
	k = int(cleaninput())
	for l in range(k):
		a = cleaninput()
		b = cleaninput()
		print levDist(a, b)

if __name__ == '__main__':
	main()