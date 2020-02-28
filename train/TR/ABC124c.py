s = input()
a = [int(c) for c in s]

def ans1(a):
	c = 0
	for i in range(len(a)):
		if(i%2 == 0 and a[i]==1):
			c = c + 1
		elif(i%2 == 1 and a[i] == 0):
			c = c + 1
	return c
	
def ans2(a):
	c = 0
	for i in range(len(a)):
		if(i%2 == 0 and a[i]==0):
			c = c + 1
		elif(i%2 == 1 and a[i] == 1):
			c = c + 1
	return c

ans = min(ans1(a), ans2(a))
print(ans)