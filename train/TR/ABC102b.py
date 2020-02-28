N = int(input())
A_list = list(map(int, input().split()))
a = max(A_list)
diff = 0
for i in A_list:
	b = abs(a - i)
	if b > diff:
		diff = b
print(diff)