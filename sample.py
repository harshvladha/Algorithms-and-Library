import sys,math
myprint = sys.stdout.write
def cleaninput():
	return raw_input().strip()

def getint():
	return int(cleaninput())

def getints():
	return map(int, cleaninput().split())

def totalDigits(number):
	return int(math.floor(math.log10(abs(number))))+1
	
def reverseDigits(number):
	length = totalDigits(number) - 1
	reverse = 0 
	while number>0:
		multiplier = 10**length
		reverse += (number%10)*multiplier
		number /= 10
		length-=1
	return reverse

def main():
	t = getint()
	print totalDigits(t), reverseDigits(t)


if __name__ == '__main__':
	main()