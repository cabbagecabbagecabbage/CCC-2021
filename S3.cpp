#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int nax = 2e5 + 5;
ll P[nax],W[nax],D[nax];
int n;

ll calc(int pos) {
	ll ret = 0;
	for (int i = 0; i < n; ++i){
		ret += max(0ll, abs(pos - P[i]) - D[i])*W[i];
	}
	return ret;
}

ll solve(ll left, ll right) {
	if (left >= right - 1) return min(calc(left),calc(right));
	
	ll third = (right - left) / 3;
	ll a = max(left + third, left + 1), b = min(right - third, right - 1);
	ll ca = calc(a), cb = calc(b);
	
	if (ca == cb) return min(solve(a, b), min(solve(left, a), solve(b, right)));
	if (ca > cb) return solve(a,right);
	if (cb > ca) return solve(left,b);
}
	
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> P[i] >> W[i] >> D[i];
	}
	cout << solve(0, 1000000000) << "\n";
	return 0;
}