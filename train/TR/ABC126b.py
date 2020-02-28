S = int(input())
a = int(S / 100)
b = S - a*100
if a <=12 and b <= 12 and a > 0 and b > 0:
    print("AMBIGUOUS")
elif a <= 12  and a > 0:
    print("MMYY")
elif b<= 12 and b > 0:
    print("YYMM")
else:
    print("NA")