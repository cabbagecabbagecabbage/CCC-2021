#include <bits/stdc++.h>
using namespace std;
const int nax = 15e4 + 5;

struct Node{
	int l, r, val, lazy = 1;
};

int n,m,x,y,z;
vector<tuple<int,int,int>> satisfy;
Node tree[nax*4];

int gcd(int a, int b){return b == 0 ? a : gcd(b, a%b);}
int lcm(int a, int b){return a * b / gcd(a, b);}

void pushup(int v){
	int left = v << 1, right = left | 1;
	tree[v].val = gcd(tree[left].val, tree[right].val);
}

void pushdown(int v){
	int left = v << 1, right = left | 1;
	tree[left].lazy = lcm(tree[left].lazy, tree[v].lazy);
	tree[right].lazy = lcm(tree[right].lazy, tree[v].lazy);
	tree[left].val = lcm(tree[left].val, tree[v].lazy);
	tree[right].val = lcm(tree[right].val, tree[v].lazy);
	tree[v].lazy = 1;
}

void build(int v, int l, int r){
	tree[v].l = l; tree[v].r = r;
	if (l == r){
		tree[v].val = 1;
		return;
	}
	int m = (l + r) / 2, left = v << 1, right = left | 1;
	build(left, l, m);
	build(right, m + 1, r);
	pushup(v);
}

void update(int v, int ql, int qr, int val){
	int l = tree[v].l, r = tree[v].r;
	if (l > qr || r < ql){
		return;
	}
	else if (ql <= l && r <= qr){
		tree[v].val = lcm(tree[v].val, val);
		tree[v].lazy = lcm(tree[v].lazy, val);
		return;
	}
	int left = v << 1, right = left | 1;
	pushdown(v);
	update(left, ql, qr, val);
	update(right, ql, qr, val);
	pushup(v);
}

int query(int v, int ql, int qr){
	int l = tree[v].l, r = tree[v].r;
	if (l > qr || r < ql){
		return -1;
	}
	else if (ql <= l && r <= qr){
		return tree[v].val;
	}
	int left = v << 1, right = left | 1;
	pushdown(v);
	int a = query(left, ql, qr);
	int b = query(right, ql, qr);
	if (a == -1) return b;
	if (b == -1) return a;
	return gcd(a,b);
}

void out(int v, int l, int r){
	tree[v].l = l; tree[v].r = r;
	if (l == r){
		cout << tree[v].val << " ";
		return;
	}
	int m = (l + r) / 2, left = v << 1, right = left | 1;
	pushdown(v);
	out(left, l, m);
	out(right, m + 1, r);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	build(1,1,n);
	while (m--){
		cin >> x >> y >> z;
		update(1,x,y,z);
		satisfy.emplace_back(x,y,z);
	}
	
	for (tuple<int,int,int> k: satisfy){
		tie(x,y,z) = k;
		if (query(1,x,y) != z){
			cout << "Impossible" << "\n";
			return 0;
		}
	}
	out(1,1,n); cout << "\n";
	return 0;
}
