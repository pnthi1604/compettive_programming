#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = 1000;
const ll INF = (ll)1e18;
struct Adj {
	int v;
	int w;
};
vector<Adj> adj[N];
int n, m;
ll cost[N], bike[N], cost_bike[N];
ll dist[N][N];

struct cmp {
	bool operator() (int x, int y) const {
		if(cost[x] != cost[y])
			return cost[x] < cost[y];
		return x < y;
	}
};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			adj[i].clear();
		for(int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		for(int i = 0; i < n; i++) cin >> cost_bike[i];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				dist[i][j] = INF;
		for(int i = 0; i < n; i++) dist[i][i] = 0;
		auto dj = [&](int s) -> void {
			multiset<int, cmp> ms;
			for(int i = 0; i < n; i++) {
				cost[i] = INF;
				bike[i] = i;
			}
			ms.insert(s);
			cost[s] = 0;
			while(ms.size()) {
				int u = *ms.begin();
				ms.erase(ms.find(u));
				for(auto[v, w] : adj[u]) {
					// cerr << u << ' ' << v << ' ' << w << endl;
					if(cost[v] > cost[u] + cost_bike[bike[u]] * w) {
						if(ms.find(v) != ms.end())
							ms.erase(ms.find(v));
						cost[v] = cost[u] + cost_bike[bike[u]] * w;
						ms.insert(v);
						if(cost_bike[bike[u]] < cost_bike[v])
							bike[v] = bike[u];
						else
							bike[v] = v;
					}
				}
			}
			for(int i = 0; i < n; i++)
				dist[s][i] = min(dist[s][i], cost[i]);
		};
		for(int i = 0; i < n; i++)
			dj(i);
		// for(int i = 0; i < n; i++) 
		// 	for(int j = 0; j < n; j++)
		// 		cerr << "dist[" << i << "][" << j << "] = " << dist[i][j] << endl;
		int u = 0;
		for(int v = 0; v < n; v++) {
			for(int k = 0; k < n; k++) {
				if(dist[u][k] != INF && dist[k][v] != INF && dist[u][v] > dist[u][k] + dist[k][v]) {
					dist[u][v] = dist[u][k] + dist[k][v];
				}
			}
		}
		cout << dist[0][n - 1] << endl;
	}
	return 0;
}