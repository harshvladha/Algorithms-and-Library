for _ in range(int(raw_input())):
	raw_input()
	eq = raw_input().strip().split()

	prev = None
	op = None
	for c in eq:
		if prev == None:
			prev = c
		elif op == None or c == '+' or c == '-' or c == '*' or c == '/':
			op = c
		elif c == '=':
			break
		else:
			prev = str(eval(prev+op+c))
	print prev