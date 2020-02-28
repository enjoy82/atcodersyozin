def gcd(a,b):
    if a%b == 0:
        return b
    else:
        return gcd(b, a%b)
 
N = int(input())
a_list = list(map(int, input().split()))
ans = []
for i in range(N-1):
    b = gcd(a_list[i], a_list[i+1])
    ans.append(b)
if N > 2:
    b = gcd(a_list[0], a_list[N-1])
    ans.append(b)
if N == 2:
    print(max(a_list))
else:
    ans.sort()
    j = 0
    for i in range(N,2):
        if ans[i] % ans[2] != 0:
            j = 1
    if j == 0:
        print(ans[2])
    else:
        print(ans[1])