#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define vll vector<ll>

using namespace std;

const int N = (int)1e5;
const int K = 21;
int p[N][K];
vi adj[N];
int vis[N], d[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	auto ae = [&](int u, int v) -> void {
		adj[u].pb(v);
	};
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		ae(u, v);
		ae(v, u);
	}
	auto bfs = [&]() -> void {
		queue<int> q;
		q.push(0);
		vis[0] = 1;
		d[0] = 1;
		p[0][0] = 0;
		while(q.size()) {
			int u = q.front();
			for(int v : adj[u]) {
				if(vis[v]) continue;
				p[v][0] = u;
				d[v] = d[u] + 1;
				for(int i = 1; i < K; i++) {
					p[v][i] = p[p[v][i - 1]][i - 1];
				}
				vis[v] = 1;
				q.push(v);
			}
		}
	};
	bfs();
	auto lca = [&](int u, int v) -> int {
		if(d[u] < d[v]) swap(u, v);
		for(int i = K - 1; i >= 0; i--) {
			if(d[p[u][i]] >= d[v])
				u = p[u][i];
		}
		if(u == v) return u;
		for(int i = K - 1; i >= 0; i--) {
			if(p[u][i] != p[v][i]) {
				u = p[u][i];
				v = p[v][i];
			}
		}
		return p[u][0];
	};
	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u - 1, v - 1) + 1 << endl;
	}
	struct dsu {
		vi p, s;
		int n;
		void init(int _n) {
			n = _n;
			p.resize(n);
			s.resize(n);
			for(int i = 0; i < n; i++) {
				p[i] = i;
				s[i] = 1;
			}
		}
		int find_par(int u) {
			return (u == p[u] ? u : (p[u] = find_par(p[u])));
		}
		bool union_sets(int u, int v) {
			u = find_par(u);
			v = find_par(v);
			if(v == u) return false;
			if(s[u] < s[v]) swap(u, v);
			p[v] = u;
			s[u] += s[v];
			return true;
		}
	};
	return 0;
}