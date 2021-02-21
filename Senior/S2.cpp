#include <bits/stdc++.h>
using namespace std;

const int nax = 5e6 + 5;
int row[nax], col[nax], m, n, k, idx;
char op;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> m >> n >> k;
	while (k--){
		cin >> op >> idx;
		if (op == 'R'){
			row[idx] += 1;
		}
		else{
			col[idx] += 1;
		}
	}
	int ans = 0;
	for (int r = 1; r <= m; r++){
		for (int c = 1; c <= n; c++){
			ans += (row[r]+col[c])%2;
		}
	}
	cout << ans << "\n";
	return 0;
}
