import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

def main():
	N = getint()
	slices = {"1/4":0, "1/2":0, "3/4":0}
	ans = 1
	for _ in range(N):
		size = cleaninput()
		slices[size]+=1
	ans += slices["3/4"]

	slices["1/4"] -= slices["3/4"]

	ans += (slices["1/2"])/2

	if slices["1/2"]%2:
		ans += 1
		slices["1/4"] -= 2
	
	if slices["1/4"] > 0:
		ans += (slices["1/4"])/4
		if slices["1/4"]%4 :
			ans+=1

	print ans


if __name__ == '__main__':
	main()