aa = input()
bb = input()
for i in range(len(aa)):
	cc = a[i]
	dd = b[i]
	if cc != dd:
		if cc == "@":
			if dd == "a" or dd == "t" or dd == "c" or dd == "o" or dd == "d" or dd == "e" or dd == "r":
			else:
				print("You will lose")
				break
		elif dd == "@":
			if cc == "a" or cc == "t" or cc == "c" or cc == "o" or cc == "d" or cc == "e" or cc == "r":
			else:
				print("You will lose")
				break
		else:
			print("You will lose")
			break
else:
print("You can win")