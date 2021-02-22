m, n, k = int(input()), int(input()), int(input())
R = [0]*m
C = [0]*n 
for i in range(k):
    arr, spos = input().split()
    spos = int(spos) - 1
    if arr == 'R':	
    	R[spos] ^= 1
    else:
    	C[spos] ^= 1
r, c = sum(R), sum(C)
print(m * c + n * r - 2 * r * c)
