m,n,k = int(input()),int(input()),int(input())
row = [0 for i in range(m+1)]
col = [0 for i in range(n+1)]
for i in range(k):
	op,num = input().split()
	num = int(num)
	if op == 'C':
		col[num] += 1
	else:
		row[num] += 1

ans = 0
for i in range(1,m+1):
	for j in range(1,n+1):
		ans += (row[i] + col[j]) % 2
print(ans)