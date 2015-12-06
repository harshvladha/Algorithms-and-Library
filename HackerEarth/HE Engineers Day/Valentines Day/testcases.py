from random import randint
#f = open('1i.txt', 'w')
T = randint(30,30)
#f.write(T+"\n")
print T
for t in range(int(T)):
	h = randint(1500,2000)
	fu = randint(10000,100000)
	print h,fu
	#f.write(h+" "+fu+"\n")
	for _ in range(int(fu)):
		n = str(randint(1,int(h)))
		m = str(randint(1,int(h)))
		print n, m
		#string = n+" "+m+"\n"
		#print string
		#f.write("Hello")
    	#f.write(string)
#f.close()
