import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

def getfloat():
	return float(cleaninput())

def getfloats():
	return map(float, cleaninput().split())

def main():
	while True:
		code = cleaninput()
		if code[0] == '0':
			break
		dp = []
		for _ in range(5002):
			dp.append(0)

		dp[0] = 1

		for i in range(1,len(code)):
			de = (ord(code[i-1]) - ord('0'))*10 + (ord(code[i]) - ord('0'))
			#print de
			if code[i]!='0':
				dp[i] = dp[i-1]
			if de > 9 and de < 27:
				if i-2 < 0:
					dp[i] += dp[0]
				else:
					dp[i] += dp[i-2]
			#print dp[i]
		print dp[len(code)-1]


if __name__ == '__main__':
	main()