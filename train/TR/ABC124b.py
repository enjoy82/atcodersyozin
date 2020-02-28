N = int(input())
h_list = list(map(int,input().split()))
a = 0
ans = 0
for i in range(len(h_list)):
	if(h_list[i] >= a):
		ans = ans + 1
		a = h_list[i]
print(ans)