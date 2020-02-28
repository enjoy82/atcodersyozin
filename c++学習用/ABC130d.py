N, k = map(int, input().split())
dp=[[0 for i in range(N)] for j in range(N)]
a = list(map(int, input().split()))
ans = 0
for i in range(N):
    dp[i][i] = a[i]
    if a[i] >= k:
        ans += 1
for l in range(N):
    for m in range(l+1, N):
        dp[l][m] = dp[l][m-1] + a[m]
        if dp[l][m] >= k:
            ans += 1
print(ans)