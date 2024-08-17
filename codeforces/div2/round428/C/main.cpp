#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)1e5;
vector<int> adj[N];
int n;
int vis[N];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	double ans = 0;
	auto dfs = [&](auto dfs, int u, double res, int h) -> void {
		vis[u] = 1;
		int cnt = 0;
		for(int v : adj[u]) {
			if(vis[v]) continue;
			cnt++;
		}
		if(cnt == 0) {
			// cerr << "u = " << u << endl;
			// cerr << "res = " << res << endl;
			ans += res * h;
			return;
		}
		else 
			res *= (double)1 / cnt;
		for(int v : adj[u]) {
			if(vis[v]) continue;
			dfs(dfs, v, res, h + 1);
		}
		res *= cnt;
	};
	dfs(dfs, 0, 1, 0);
	cout << setprecision(6) << fixed << ans;
	return 0;
}