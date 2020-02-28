a,b = map(int, input().split())
if(a > b):
	print(a+a-1)
elif(a == b):
	print(a+b)
else:
	print(b+b-1)