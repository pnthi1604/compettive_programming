#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'
#define bit(n, i) ((n >> i) & 1)
#define set_bit(n, k) ((1 << k) | n)

using namespace std;

const int N = (int)2e5 + 10;
vector<int> cost;
pair<pair<int,int>,ll> cheap[N];
vector<int> g[N];
int n;

struct DSU {
	int n;
	vector<int> par, sz;
	void init() {
		n = N;
		par.resize(n);
		sz.resize(n);
		for(int i = 0; i < n; i++)
			par[i] = i, sz[i] = 1;
	}
	int f(int x) {
		return (x == par[x] ? x : (par[x] = f(par[x])));
	}
	bool same(int x, int y) {
		return f(x) == f(y);
	}
	bool U(int x, int y) {
		x = f(x), y = f(y);
		if(x == y) return false;
		if(sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y];
		par[y] = x;
		return true;
	}
	void gr() {
		for(int i = 0; i < n; i++)
			g[i].clear();
		for(int i = 0; i < n; i++)
			g[f(i)].push_back(i);
	}
} d;
struct Node {
	int cnt, id;
	int c[2];
};
struct Trie {
	int cur;
	vector<Node> nodes;
	void init() {
		nodes.resize(N * 60);
		cur = 0;
		newNode();
	}
	int newNode() {
		nodes[cur].cnt = 0;
		nodes[cur].id = -1;
		for(int i = 0; i < 2; i++) nodes[cur].c[i] = -1;
		return cur++;
	}
	void addString(int n, int idx) {
		int pos = 0;
		for(int i = 30; i >= 0; i--) {
			int x = bit(n, i);
			if(nodes[pos].c[x] == -1)
				nodes[pos].c[x] = newNode();
			pos = nodes[pos].c[x];
			nodes[pos].cnt++;
		}
		nodes[pos].id = idx;
	}
	bool delString(int n, int pos, int i) {
		if(i != -1) {
			int x = bit(n, i);
			bool del = delString(n, nodes[pos].c[x], i - 1);
			if(del)
				nodes[pos].c[x] = -1;
		}
		if(pos) {
			nodes[pos].cnt--;
			return nodes[pos].cnt == 0;
		}
		return false;
	}
	void delString(int n) {
		delString(n, 0, 30);
	}
	int query(int n) {
		int pos = 0;
		for(int i = 30; i >= 0; i--) {
			int x = bit(n, i);
			if(nodes[pos].c[x] != -1 && nodes[nodes[pos].c[x]].cnt) {
				pos = nodes[pos].c[x];
			} else {
				pos = nodes[pos].c[x ^ 1];
			}
		}
		return nodes[pos].id;
	}
}t;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	map<int,bool> vis;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(vis[x]) continue;
		vis[x] = true;
		cost.push_back(x);
	}
	n = cost.size();
	d.init();
	t.init();
	int cnt_tree = n;
	ll total = 0;
	for(int i = 0; i < n; i++)
		t.addString(cost[i], i);
	while(cnt_tree > 1) {
		for(int i = 0; i < n; i++)
			cheap[i] = {{-1, -1}, -1};
		d.gr();
		for(int i = 0; i < n; i++) {
			for(int x : g[i]) {
				t.delString(cost[x]);
			}
			for(int v : g[i]) {
				int x = cost[v];
				int idx = t.query(x);
				int f = cost[idx];
				if(!d.same(idx, v) && (cheap[i].second == -1 || cheap[i].second > (f ^ x))) {
					cheap[i] = {{v, idx}, f ^ x};
				}
			}
			for(int x : g[i]) {
				t.addString(cost[x], x);
			}
		}
		for(int i = 0; i < n; i++) {
			if(cheap[i].second != -1 && d.U(cheap[i].first.first, cheap[i].first.second)) {
				total += cheap[i].second, cnt_tree--;
			}
		}
	}
	cout << total;
	return 0;
}