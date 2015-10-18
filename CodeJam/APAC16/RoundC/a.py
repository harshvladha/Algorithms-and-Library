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
		names = {}
		nosp = getint()
		p  = getints()
		n = getint()
		for i in xrange(n):
			winners = cleaninput().split()
			weight = int(winners[0])
			for j in xrange(nosp):
				point = weight * p[j]
				if winners[j+1] in names:
					names[winners[j+1]].append(point)
				else:
					names[winners[j+1]] = [point]
		m = getint()
		final = {}
		#print names
		for i in names:
			score = 0
			names[i].sort(reverse=True)
			#print i, names[i]
			for j in xrange(m):
				try:
					score += names[i][j]
				except IndexError:
					pass
				final[i] = score
		#print final
		ult = [v[0] for v in sorted(final.iteritems(), key=lambda(k, v): (-v, k))]
		print "Case #{0}:".format((_+1))
		last = -10000
		last_id = 1
		for i in xrange(len(ult)):
			if final[ult[i]] == last:
				print "{0}: {1}".format(last_id, ult[i])
			else:
				last = final[ult[i]]
				last_id = i+1
				print "{0}: {1}".format(i+1, ult[i])






