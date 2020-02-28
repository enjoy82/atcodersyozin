N,K = map(int, input().split())
S = list(input())
s = S.pop(K-1)
s = s.lower()
S.insert(K-1, s)
ans = ""
for x in S:
    ans += x
print(ans)