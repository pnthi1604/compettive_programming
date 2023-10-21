#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = (int)1e5, maxm = (int)2e5;
const int inf = (int)1e18;
vector<int> adj[maxn];
int n, m;
vector<int> power(maxn);

void buildGraph(int d) {
	for(int i = 0; i < n; i++) {
		adj[i].clear();
	}
}

int dj(int maxPower) {
	vector<int> dist(n, inf);
	dist[0] = 0;
	multiset<pair<int,int>> ms;
	ms.insert({1, 0});
	while(ms.size()) {
		auto[distu, u] = *ms.begin();
		ms.erase(ms.find({distu, u}));
		for(int v : adj[u]) {
			if(power[v] <= maxPower && dist[v] > distu + 1) {
				if(ms.find({dist[v], v}) != ms.end())
					ms.erase(ms.find({dist[v], v}));
				dist[v] = distu + 1;
				ms.insert({dist[v], v});
			}
		}
	}
	return dist[n - 1] == inf ? -1 : dist[n - 1];
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int maxPower = 0;
	for(int i = 0; i < n; i++) {
		cin >> power[i];
		maxPower = max(maxPower, power[i]);
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = inf;
	int l = max(power[0], power[n - 1]), r = maxPower + 1;
	while(l <= r) {
		int x = (l + r) / 2;
		int y = dj(x);
		if(y == -1) {
			l = x + 1;
		} else {
			ans = min(ans, abs(y - x));
			r = x - 1;
		}
	}
	cout << (ans == inf ? -1 : ans);
}