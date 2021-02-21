big = -1
name = ""
for i in range(int(input())):
	nam, amt = input(),int(input())
	if amt > big:
		name = nam
		big = amt
print(name)