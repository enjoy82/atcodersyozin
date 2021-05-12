def gcd(aa, bb):
    if aa % bb ==0:
        return bb
    else:
        return gcd(bb, aa%bb)

def lcm(aa, bb):
    return aa / gcd(aa, bb) * bb

a, b = map(int, input().split())

print(lcm(a, b))