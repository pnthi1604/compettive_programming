#include <bits/stdc++.h>
#define int long long
 
using namespace std;

const int maxn = 2500, maxm = 5000, inf = (int)1e18;
int n, m; 

struct Edge {
	int u, v, w;
};

vector<Edge> edges;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		edges.push_back({u, v, w});
	}
	vector<int> dist(n, inf), par(n, -1);
	dist[0] = 0;
	int start = -1;
	for(int i = 0; i < n; i++) {
		for(auto[u, v, w] : edges) {
			if(dist[v] == inf || dist[v] > dist[u] + w) {
				if(i == n - 1)
					start = v;
				dist[v] = dist[u] + w;
				par[v] = u;
			}
		}
	}
	if(start == -1) 
		cout << "NO";
	else {
		for(int i = 0; i < n - 1; i++) 
			start = par[start];
		vector<int> res(1, start);
		start = par[start];
		while(start != res[0]) {
			res.push_back(start);
			start = par[start];
		}
		res.push_back(start);
		reverse(res.begin(), res.end());
		cout << "YES\n";
		for(int x : res)
			cout << x + 1 << ' ';
	}
}