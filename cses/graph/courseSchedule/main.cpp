#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = (int)1e5, maxm = (int)2e5;
int n, m;
vector<int> adj[maxn], deg(maxn, 0), color(maxn, -1), st;
bool isC;

void dfs(int u) {
	if(isC)
		return;
	color[u] = 1;
	for(int v : adj[u]) {
		if(color[v] == 1) {
			isC = true;
			break;
		}
		if(color[v] == -1) {
			dfs(v);
		}
	}
	st.push_back(u);
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
		deg[v]++;
	}
	for(int i = 0; i < n; i++) {
		if(deg[i] == 0)
			dfs(i);
	}
	if(isC || st.size() != n) {
		cout << "IMPOSSIBLE";
	} else {
		reverse(st.begin(), st.end());
		for(int x : st) 
			cout << x + 1 << ' ';
	}
}