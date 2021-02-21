#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int nax = 2e5 + 5;
int dist[nax], n, w, d, a, b, x, y, arr[nax];
vector<int> adj[nax];
queue<int> q;

void bfs(){
	q.push(n);
	memset(dist,inf,sizeof(dist));
	dist[n] = 0;
	while (!q.empty()){
		int node = q.front(); q.pop();
		for (int x: adj[node]){
			if (dist[x] > dist[node] + 1){
				dist[x] = dist[node] + 1;
				q.push(x);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> w >> d;
	while (w--){
		cin >> a >> b;
		adj[b].emplace_back(a);
	}
	bfs();
	multiset<int> best;
	for (int i = 1; i <= n; ++i){
		cin >> arr[i];
		if (dist[arr[i]] != inf) best.insert(dist[arr[i]] + i - 1);
	}
	while (d--){
		cin >> x >> y;
		if (dist[arr[x]] != inf){
			best.erase(best.find(dist[arr[x]] + x - 1));
			best.insert(dist[arr[x]] + y - 1);
		}
		if (dist[arr[y]] != inf){
			best.erase(best.find(dist[arr[y]] + y - 1));
			best.insert(dist[arr[y]] + x - 1);
		}
		swap(arr[x],arr[y]);
		cout << *best.begin() << "\n";
	}
	return 0;
}
