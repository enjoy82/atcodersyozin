N = int(input())
ans = [2] * N
memo = []
Mu = []
Mv = []
Mw = []
for i in range(N-1):
    u, v, w = map(int, input().split())
    Mu.append(u)
    Mv.append(v)
    Mw.append(w)
ans[0] = 1
memo.append(1)
for a in range(N-1):
    for b in memo:
        for c in range(N-1):
            if Mu[c] == b:
                memo.append(Mv[c])
                if Mw[c] % 2 == 0:
                    if ans[b-1] == 1:
                        ans[Mv[c]-1] = 1
                    else:
                        ans[Mv[c]-1] = 0
                else:
                    if ans[b-1] == 1:
                        ans[Mv[c]-1] = 0
                    else:
                        ans[Mv[c]-1] = 1
            elif Mv[c] == b:
                memo.append(Mu[c])
                if Mw[c] % 2 == 0:
                    if ans[b-1] == 1:
                        ans[Mu[c]-1] = 1
                    else:
                        ans[Mu[c]-1] = 0
                else:
                    if ans[b-1] == 1:
                        ans[Mu[c]-1] = 0
                    else:
                        ans[Mu[c]-1] = 1
for e in ans:
    print(e)