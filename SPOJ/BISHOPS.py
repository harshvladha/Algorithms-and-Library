import sys

for line in sys.stdin:
	t = int(line.strip())
	if t == 0:
		print 0
	if t == 1:
		print 1
	if t > 1:
		print 2*(t-1)