m = int(input());
n = int(input());
k = int(input());
gold = {'R':[0]*m, 'C':[0]*n};
for i in range(k):
    arr, spos = input().split();
    gold[arr][int(spos) - 1] = (gold[arr][int(spos) - 1] + 1) % 2;
r, c = sum(gold['R']), sum(gold['C']);
print(m * c + n * r - 2 * r * c);
