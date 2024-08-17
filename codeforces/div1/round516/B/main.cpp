#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = 2010;
const int INF = (int)1e9;
vector<pair<pair<int,int>,int>> adj[N][N];
int d[N][N];
int n, m;
int vis[N][N];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int s, t, x, y;
	cin >> s >> t >> x >> y;
	s--, t--;
	vector<string> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {-1, 1, 0, 0};
	auto ok = [&](int i, int j) -> bool {
		return i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.';
	};
	auto build_graph = [&]() -> void {
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < m; j++)
				adj[i][j].clear();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][j] == '*') continue;
				for(int t = 0; t < 4; t++) {
					int ii = i + dx[t];
					int jj = j + dy[t];
					if(!ok(ii, jj)) continue;
					if((t == 0)) {
						adj[i][j].push_back({{ii, jj}, 1});
					} else {
						adj[i][j].push_back({{ii, jj}, 0});
					}
				}
			}
		}
	};
	auto bfs0_1 = [&]() -> void {
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) 
				d[i][j] = INF;
		d[s][t] = 0;
		deque<pair<int,int>> q;
		q.push_front({s, t});
		while(q.size()) {
			auto[s, t] = q.front();
			q.pop_front();
			for(auto x : adj[s][t]) {
				auto[u, v] = x.first;
				int w = x.second;
				if(d[u][v] > d[s][t] + w) {
					d[u][v] = d[s][t] + w;
					if(w)
						q.push_back({u, v});
					else
						q.push_front({u, v});
				}
			}
		}
	};
	build_graph();
	bfs0_1();
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '*') continue;
			int l = d[i][j];
			int r = l + j - t;
			if(l <= x && r <= y) vis[i][j] = 1;
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ans += vis[i][j];
	cout << ans;
	return 0;
}