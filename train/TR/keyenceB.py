a = [c for c in input()]
judge = 0
if "k" in a:
	if a.index("k") != 0:
		judge = judge + 1
	del a[:a.index("k")+1]
	if "e" in a:
		if a.index("e") != 0:
			judge = judge + 1
		del a[:a.index("e")+1]
		if "y" in a:
			if a.index("y") != 0:
				judge = judge + 1
			del a[:a.index("y")+1]
			if "e" in a:
				if a.index("e") != 0:
					judge = judge + 1
				del a[:a.index("e")+1]
				if "n" in a:
					if a.index("n") != 0:
						judge = judge + 1
					del a[:a.index("n")+1]
					if "c" in a:
						if a.index("c") != 0:
							judge = judge + 1
						del a[:a.index("c")+1]
						if "e" in a:
							if a.index("e") != 0:
								judge = judge + 1
							if judge == 0 or judge == 1:
								print("YES")
							else:
								print("NO")
						else:
							print("NO")
					else:
						print("NO")
				else:
					print("NO")
			else:
				print("NO")
		else:
			print("NO")
	else:
		print("NO")
else:
	print("NO")