import sys,math

myprint = sys.stdout.write

check = ["TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"]

for _ in range(int(raw_input())):
	t = raw_input().strip()
	s = raw_input().strip()
	myprint(t + " ")
	for match_str in check:
		count = 0
		for j in range(len(s)):
			if s[j:j+3] == match_str:
				count+=1
		
		myprint(str(count)+ " ")