import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def main():
	for _ in range(int(cleaninput())):

		n = int(cleaninput())
		print (n*(n+1) + (n*(n-1))/2)%1000007

if __name__ == '__main__':
	main()