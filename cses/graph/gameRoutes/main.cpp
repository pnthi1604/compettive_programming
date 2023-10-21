#include <bits/stdc++.h>
#define int long long
#define cerr << "HIHIHI\n";

using namespace std;
const int mod = (int)1e9 + 7, maxn = (int)1e5;
vector<int> adj[maxn], sumDist(maxn, -1);

int dfs(int u) {
	int res = 0;
	for(int v : adj[u]) {
		if(sumDist[v] == -1)
			dfs(v);
		res += sumDist[v];
		res %= mod;
	}
	return sumDist[u] = res;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
	}
	sumDist[n - 1] = 1;
	cout << dfs(0);
}