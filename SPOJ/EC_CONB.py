for _ in range(int(raw_input().strip())):
	x = int(raw_input().strip())
	if(x%2):
		print x
	else:
		x = bin(int(x))[2:]	
		print int(x[::-1],2)
	