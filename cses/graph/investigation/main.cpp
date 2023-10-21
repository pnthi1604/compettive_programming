#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = (int)1e9 + 7, maxn = (int)1e5, maxm = (int)2e5;
const int inf = (int)1e18;
int n, m;
vector<pair<int,int>> adj[maxn];

void dj() {
	multiset<pair<int,int>> ms;
	vector<int> dist(n, inf), cntDist(n, inf), maxFlight(n, -inf), minFlight(n, inf);
	ms.insert({0, 0});
	dist[0] = 0;
	cntDist[0] = 1;
	minFlight[0] = maxFlight[0] = 0;
	while(ms.size()) {
		auto[distu, u] = *ms.begin();
		ms.erase(ms.find({distu, u}));
		for(auto[wuv, v] : adj[u]) {
			if(dist[v] > distu + wuv) {
				if(ms.find({dist[v], v}) != ms.end())
					ms.erase(ms.find({dist[v], v}));
				dist[v] = distu + wuv;
				cntDist[v] = cntDist[u];
				minFlight[v] = minFlight[u] + 1;
				maxFlight[v] = maxFlight[u] + 1;
				ms.insert({dist[v], v});
			} else if(dist[v] == distu + wuv) {
				cntDist[v] += cntDist[u];
				cntDist[v] %= mod;
				minFlight[v] = min(minFlight[v], minFlight[u] + 1);
				maxFlight[v] = max(maxFlight[v], maxFlight[u] + 1);
			}
		}
	}
	cout << dist[n - 1] << ' ' << cntDist[n - 1] << ' ' << minFlight[n - 1] << ' ' << maxFlight[n - 1];
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].push_back({w, v});
	}
	dj();
}