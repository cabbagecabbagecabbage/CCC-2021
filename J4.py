b = input()
ans = 0
temp = 0
lc = b.count("L")
mc = b.count("M")
sc = b.count("S")
# [0,lc-1] : interval of L
# [lc,lc+mc-1] : interval of M
# [lc+mc,lc+mc+sc-1] : interval of S

sinl = b[:lc].count("S")
lins = b[lc+mc:lc+mc+sc].count("L")
ans += min(lins,sinl)
temp += abs(lins-sinl)

minl = b[:lc].count("M")
linm = b[lc:lc+mc].count("L")
ans += min(linm,minl)
temp += abs(linm-minl)

sinm = b[lc:lc+mc].count("S")
mins = b[lc+mc:lc+mc+sc].count("M")
ans += min(mins,sinm)
temp += abs(mins-sinm)

ans += temp // 3 * 2 # resolving cycles
print(ans)