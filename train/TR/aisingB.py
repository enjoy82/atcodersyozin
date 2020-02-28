N = int(input())
A,B = map(int, input().split())
P = list(map(int, input().split()))
list = [0, 0, 0]
for i in range(N):
	if P[i] <= A:
		list[0] = list[0] + 1
	elif P[i] > A and P[i] <= B:
		list[1] = list[1] + 1
	else:
		list[2] = list[2] + 1
print(min(list))