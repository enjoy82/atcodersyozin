N = int(input())
a = []
for i in range(N):
    b = list(input().split())
    b[1] = int(b[1])
    b.append(i+1)
    a.append(b)
c = sorted(a, key = lambda x:(x[0], -x[1]))
for l in range(N):
    print(c[l][2])