#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = (int)1e5, maxm = (int)2e5;
int n, m, start = -1;
vector<int> adj[maxn], par(maxn, -1), deg(maxn, 0);
vector<int> color(maxn, -1);

void dfs(int u) {
	if(start != -1)
		return;
	color[u] = 1;
	for(int v : adj[u]) {
		if(start != -1)
			break;
		if(color[v] == 2)
			continue;
		par[v] = u;
		if(color[v] == -1) {
			dfs(v);
		}
		else if(color[v] == 1) {
			start = v;
		}
	}
	color[u] = 2;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		deg[u]++;
	}
	for(int i = 0; i < n; i++) {
		if(deg[i] == 0)
			dfs(i);
	}
	if(start == -1) {
		cout << "IMPOSSIBLE";
	} else {
		vector<int> res(1, start);
		start = par[start];
		while(start != res[0]) {
			res.push_back(start);
			start = par[start];
		}
		res.push_back(start);
		reverse(res.begin(), res.end());
		cout << res.size() << '\n';
		for(int x : res)
			cout << x + 1 << ' ';
	}
}