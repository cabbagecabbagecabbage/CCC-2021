import sys
input = sys.stdin.readline

n = int(input())
heights = [int(i) for i in input().split()]
widths = [int(i) for i in input().split()]
ans = 0
for i in range(n):
	ans += (heights[i]+heights[i+1])*widths[i] / 2
print(ans)