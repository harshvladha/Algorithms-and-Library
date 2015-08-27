t = input()
for _ in range(t):
	raw_input()
	n = input()
	total = 0
	for __ in range(n):
		total+=input()
	if total%n == 0:
		print "YES"
	else:
		print "NO"
