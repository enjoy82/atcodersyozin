def gcd(a,b):
    if a%b == 0:
        return b
    else:
        return gcd(b, a%b)

N = int(input())
a_list = list(map(int, input().split()))
ans = []
for l in range(N):
    c = a_list[l]
    if l != N-1:
        a_list[l] = a_list[l+1]
    else:
        a_list[l] = a_list[l-1]
    for i in range(N-1):
        b = gcd(a_list[i], a_list[i+1])
        ans.append(b)
    a_list[l] = c
if N > 2:
    ans.sort()
    print(ans[2])
else:
    print(max(a_list))