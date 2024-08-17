#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'
#define bit(n, i) ((n >> i) & 1)
#define set_bit(n, k) ((1 << k) | n)

using namespace std;

const int N = (int)1e5;
vector<pair<int,int>> adj[N];
int n;

struct Node {
	int cnt;
	int c[2];
};
struct Trie {
	int cur;
	vector<Node> nodes;
	void init(int _n) {
		nodes.resize(_n);
		cur = 0;
		newNode();
	}
	int newNode() {
		nodes[cur].cnt = 0;
		for(int i = 0; i < 2; i++) nodes[cur].c[i] = -1;
		return cur++;
	}
	void addString(int n) {
		int pos = 0;
		for(int i = 30; i >= 0; i--) {
			int x = bit(n, i);
			if(nodes[pos].c[x] == -1)
				nodes[pos].c[x] = newNode();
			pos = nodes[pos].c[x];
			nodes[pos].cnt++;
		}
	}
	int query(int n) {
		int pos = 0;
		for(int i = 30; i >= 0; i--) {
			int x = bit(n, i);
			pos = nodes[pos].c[x];
			if(pos == -1) return 0;
		}
		return nodes[pos].cnt;
	}
};

int x[N];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	auto dfs = [&](auto dfs, int u, int p) -> void {
		for(auto[v, w] : adj[u]) {
			if(v == p) continue;
			x[v] = x[u] ^ w;
			dfs(dfs, v, u);
		}
	};
	dfs(dfs, 0, -1);
	Trie t;
	t.init(N);
	int ans = 0;
	for(int i = 0; i < n; i++)
		t.addString(x[i]);
	for(int i = 0; i < n; i++) {
		int s = x[i];
		int f = 0;
		for(int j = 30; j >= 0; j--) {
			int bitj = bit(s, j);
			int tmp_f = f;
			if(!bitj)
				tmp_f = set_bit(tmp_f, j);
			if(t.query(tmp_f)) f = tmp_f;
		}
		ans = max(ans, f ^ s);
	}
	cout << ans;
	return 0;
}