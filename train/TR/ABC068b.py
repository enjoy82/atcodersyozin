N = int(input())
j = 0
c2 = 0
for i in range(1, N+1):
	a = i
	c = 0
	while a % 2 == 0:
		c = c + 1
		a = a / 2
		if c >= c2:
			c2 = c
			j = i
if N == 1:
	print(1)
else:
	print(j)