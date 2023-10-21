#include <bits/stdc++.h>
#define int long long
 
using namespace std;

const int maxn = (int)1e5, maxm = (int)2e5, inf = (int)1e18;
int n, m, k;

vector<multiset<int>> dist(maxn);

vector<pair<int,int>> edges[maxn];

void dj() {
	multiset<pair<int,int>> ms;
	ms.insert({0, 0});
	dist[0].insert(0);
	while(ms.size()) {
		auto[wu, u] = *ms.begin();
		ms.erase(ms.begin());
		for(auto[wv, v] : edges[u]) {
			if(dist[v].size() < k || *dist[v].rbegin() > wu + wv) {
				if(dist[v].size() >= k) {
					ms.erase(ms.find({*dist[v].rbegin(), v}));
					dist[v].erase(dist[v].find(*dist[v].rbegin()));
				}
				dist[v].insert(wu + wv);
				ms.insert({wu + wv, v});
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		edges[u].push_back({w, v});
	}
	dj();
	for(int x : dist[n - 1]) {
		cout << x << ' ';
	}
}