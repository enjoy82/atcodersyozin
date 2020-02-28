N, K = map(int, input().split())
R = [int(i) for i in input().split()] 
S = 0
R = sorted(R)
for i in range (len(R)-K, len(R)):
	S = (S+R[i])/2
print(S)