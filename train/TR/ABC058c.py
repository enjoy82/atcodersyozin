n = int(input())
alpha = ("abcdefghijklmnopqrstuvwxyz")
ans = [100] * 26

for i in range(n):
    S = list(input())
    tmp = [0]*26
    for j in range(len(S)):
        for k in range(26):
            if S[j] == alpha[k]:
                tmp[k] += 1
    for j in range(26):
        if ans[j] > tmp[j]:
            ans[j] = tmp[j]

ansa = ""
for i in range(26):
    for j in range(ans[i]):
        ansa = ansa + alpha[i]

print(ansa)