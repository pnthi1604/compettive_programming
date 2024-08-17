#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)2e5;
int n;
int a[N];
int dp[N];
vector<int> adj[N];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	auto dfs = [&](auto dfs, int u, int p) -> int {
		int resu = (a[u] == 1 ? 1 : -1);
		// int resu = 0;
		for(int v : adj[u]) {
			if(v == p) continue;
			int resv = dfs(dfs, v, u);
			resu += max(resv, 0);
		}
		if(p == -1) return 0;
		// if(dp[u] >= 0)
		// 	dp[u] = max(dp[u], dp[p]);
		// else
		// 	dp[u] = max(dp[u], dp[u] + dp[p]);
		if(p != -1)
		dp[u] = resu + 2 * a[u] - 1;
		return resu;
	};
	dfs(dfs, 0, -1);
	// auto dfs0 = [&](auto dfs0, int u, int p) -> void {
	// 	for(int v : adj[u]) {
	// 		if(v == p) continue;
	// 		if(dp[v] >= 0)
	// 			dp[v] = max(dp[v], dp[u]);
	// 		else
	// 			dp[v] = max(dp[v], dp[u] + dp[v]);
	// 		dfs0(dfs0, v, u);
	// 	}
	// };
	// dfs0(dfs0, 0, -1);
	for(int i = 0; i < n; i++)
		cout << dp[i] << ' ';
	return 0;
}