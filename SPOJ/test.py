def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

def colorIt(n, m, x, y, d, val):
	c = 0
	p, q = x - 1, y
	if p<n and p>=0 and q<m and q>=0:
		if not marked[p][q] and abs(grid[p][q]-val) <= d:
			marked[p][q] = 1
			c += 1
			c += colorIt(n, m, p, q, d, grid[p][q])
	p, q = x + 1, y
	if p<n and p>=0 and q<m and q>=0:
		if not marked[p][q] and abs(grid[p][q]-val) <= d:
			marked[p][q] = 1
			c += 1
			c += colorIt(n, m, p, q, d, grid[p][q])
	p, q = x, y - 1
	if p<n and p>=0 and q<m and q>=0:
		if not marked[p][q] and abs(grid[p][q]-val) <= d:
			marked[p][q] = 1
			c += 1
			c += colorIt(n, m, p, q, d, grid[p][q])
	p, q = x, y + 1
	if p<n and p>=0 and q<m and q>=0:
		if not marked[p][q] and abs(grid[p][q]-val) <= d:
			marked[p][q] = 1
			c += 1
			c += colorIt(n, m, p, q, d, grid[p][q])

	return c

if __name__ == '__main__':
	n, m, q = getints()
	grid  = [getints() for j in range(n)]
	ans = 0
	for i in xrange(q):
		marked  = [[0 for i in range(m)] for j in range(n)]
		count = 0
	 	x, y, d = getints()

 		count = count + 1
 		marked[x-1][y-1] = 1
 		count += colorIt(n, m, x-1, y-1, d, grid[x-1][y-1])

	 	print count