// ONLY SUBTASK 1
#include <bits/stdc++.h>
using namespace std;
const int nax = 2005;
int arr[nax];
int n,m,x,y,z;
vector<pair<int,int>> v;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) arr[i] = 1;
	while (m--){
		cin >> x >> y >> z;
		if (z == 2){
			for (int i = x; i <= y; ++i){
				arr[i] = 2;
			}
		}
		else{
			v.emplace_back(x,y);
		}
	}
	for (pair<int,int> k: v){
		tie(x,y) = k;
		bool ok = false;
		for (int i = x; i <= y; ++i){
			if (arr[i] == 1){
				ok = true;
			}
		}
		if (ok == false){
			cout << "Impossible" << "\n";
			return 0;
		}
	}
	for (int i = 1; i <= n; ++i){
		cout << arr[i] << " ";
	}
	cout << "\n";
		


	return 0;
}