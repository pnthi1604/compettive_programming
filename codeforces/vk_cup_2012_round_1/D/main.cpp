#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)5e4;
const int K = 502;
int n, k;
vector<int> adj[N];
ll dp[N][K];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	k++;
	ll ans = 0;
	auto dfs = [&](auto dfs, int u, int p) -> void {
		dp[u][1] = 1;
		vector<ll> cnt(k + 1, 0);
		cnt[0] = 1;
		for(int v : adj[u]) {
			if(v == p) continue;
			dfs(dfs, v, u);
			for(int i = 1; i < k; i++) 
				cnt[i] += dp[v][i];
		}
		for(int i = 1; i < k; i++)
			dp[u][i + 1] = cnt[i];
		ll res = 0;
		for(int v : adj[u]) {
			if(v == p) continue;
			for(int i = 1; i < k; i++)
				cnt[i] -= dp[v][i];
			for(int i = 1; i < k; i++) {
				if(k - i - 1 >= 1)
					res += cnt[k - i - 1] * dp[v][i];
			}
			for(int i = 1; i < k; i++)	
				cnt[i] += dp[v][i];
		}
		res /= 2;
		ans += res + dp[u][k];
	};
	dfs(dfs, 0, -1);
	cout << ans;
	return 0;
}