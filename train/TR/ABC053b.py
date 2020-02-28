s = input()
for i in reversed(range(len(s))):
	if s[i] == "Z":
		break
print(i-s.index("A")+1)