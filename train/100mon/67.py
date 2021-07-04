def base10int(value, base):
    if (int(value // base)):
        return base10int(int(value // base), base) + str(value % base)
    return str(value % base)

def b8to10(s):
    mid = 0
    for i in range(len(s)):
        mid += int(s[len(s)-1-i])*(8 ** i)
    return mid

n, k = map(str, input().split(" "))

for i in range(int(k)):
    n = b8to10(n)
    n = base10int(n, 9)
    n = list(n)
    for l in range(len(n)):
        if n[l] == '8':
            n[l] = '5'
    n = "".join(n)
print(int(n))