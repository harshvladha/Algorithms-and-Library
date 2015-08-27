
operators = set(['+', '-', '*', '/', '^'])
def cleaninput():
	return raw_input().strip()

def toRPN(exp):
	operandS = []
	operatorS = []

	for c in exp:
		if c == '(':
			operandS.append('(')
			operatorS.append('(')
		elif c == ')':
			opS = []
			while operandS[-1] != '(':
				opS.insert(0, operandS.pop())
			operandS.pop()
			oprS = []
			while operatorS[-1] != '(':
				oprS.insert(0, operatorS.pop())
			operatorS.pop()

			operandS.append(solveStack(opS, oprS))

		elif c in operators:
			operatorS.append(c)
		else:
			operandS.append(c)

	return solveStack(operandS, operatorS)
	
def solveStack(operandS, operatorS):
	while len(operandS) > 1:
		if '^' in operatorS:
			op = '^'
		elif '/' in operatorS:
			op = '/'
		elif '*' in operatorS:
			op = '*'
		elif '-' in operatorS:
			op = '-'
		elif '+' in operatorS:
			op = '+'

		i = operatorS.index(op)

		newOp = operandS.pop(i) + operandS.pop(i) + operatorS.pop(i)
		operandS.insert(i, newOp)
	return operandS[0]

def main():
	for _ in xrange(int(cleaninput())):
		print toRPN(raw_input())

if __name__ == '__main__':
	main()