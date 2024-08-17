#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)7e4 + 10;
vector<int> adj[N];
int n, qq;
bool vis[N];
const int K = 20;
int par[N][21];
int d[N];

int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	for(int i = K; i >= 0; i--)
		if(d[par[u][i]] >= d[v])
			u = par[u][i];
	if(u == v) return u;
	for(int i = K; i >= 0; i--)
		if(par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	return par[u][0];
};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> qq;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q;
	q.push(0);
	vis[0] = true;
	d[0] = 1;
	par[0][0] = 0;
	while(q.size()) {
		int u = q.front();
		q.pop();
		for(int v : adj[u]) {
			if(vis[v]) continue;
			d[v] = d[u] + 1;
			par[v][0] = u;
			for(int i = 1; i <= K; i++)
				par[v][i] = par[par[v][i - 1]][i - 1];
			vis[v] = true;
			q.push(v);
		}
	}
	struct ST {
		vector<int> t;
		int n;
		void init(int _n) {
			n = _n;
			t.resize(4 * n);
			build(1, 0, n - 1);
		}
		void build(int id, int l, int r) {
			if(l == r) {
				t[id] = l;
				return;
			}
			int m = (l + r) / 2;
			build(id * 2, l, m);
			build(id * 2 + 1, m + 1, r);
			combine(id);
		}
		int combine(int a, int b) {
			if(a == -1) return b;
			if(b == -1) return a;
			return lca(a, b);
		}
		void combine(int id) {
			t[id] = combine(t[id * 2], t[id * 2 + 1]);
		}
		int get(int id, int l, int r, int u, int v) {
			if(l > v || r < u) return -1;
			if(l >= u && r <= v) return t[id];
			int m = (l + r) / 2;
			int get1 = get(id * 2, l, m, u, v);
			int get2 = get(id * 2 + 1, m + 1, r, u, v);
			return combine(get1, get2);
		}
		int get(int u, int v) {
			return get(1, 0, n - 1, u, v);
		}
	};
	ST st;
	st.init(n);
	while(qq--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		cout << st.get(u, v) + 1 << endl;
	}
	return 0;
}