prev = "right"
while 1:
	n = input()
	if n == "99999":
		break
	s = int(n[0]) + int(n[1])
	if s == 0:
		print(prev, n[2:])
	elif s % 2:
		print("left", n[2:])
		prev = "left"
	else:
		print("right", n[2:])
		prev = "right"
