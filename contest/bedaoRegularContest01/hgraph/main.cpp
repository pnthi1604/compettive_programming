#include <bits/stdc++.h>
#define int long long

using namespace std;

const int inf = (int)1e18;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	a[n - 1][m - 1] = 0;
	vector<pair<int,int>> graph[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			for(int t = 0; t < 4; t++) {
				 int ii = i + dx[t], jj = j + dy[t];
				 if(ii >= 0 && ii < n && jj >= 0 && jj < m) {
				 	graph[i][j].push_back({ii, jj});
				 }
			}
			if(a[i][j]) {
				for(int il = i - 1; il >= 0; il--) {
					graph[i][j].push_back({il, j});
					if(a[il][j] == 1)
						break;
				}
				for(int ir = i + 1; ir < n; ir++) {
					graph[i][j].push_back({ir, j});
					if(a[ir][j] == 1)
						break;
				}
				for(int jl = j - 1; jl >= 0; jl--) {
					graph[i][j].push_back({i, jl});
					if(a[i][jl] == 1)
						break;
				}
				for(int jr = j + 1; jr < m; jr++) {
					graph[i][j].push_back({i, jr});
					if(a[i][jr] == 1)
						break;
				}
			}
		}
	}
	int dist[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			dist[i][j] = inf;
	}
	multiset<pair<int,pair<int,int>>> ms;
	ms.insert({0, {0, 0}});
	dist[0][0] = 0;
	while(ms.size()) {
		auto top = *ms.begin();
		ms.erase(ms.find(top));
		int distu = top.first;
		auto[u1, u2] = top.second;
		for(auto[v1, v2] : graph[u1][u2]) {
			if(dist[v1][v2] > distu + 1) {
				if(ms.find({dist[v1][v2], {v1, v2}}) != ms.end())
					ms.erase(ms.find({dist[v1][v2], {v1, v2}}));
				dist[v1][v2] = distu + 1;
				ms.insert({dist[v1][v2], {v1, v2}});
			}
		}
	}
	cout << dist[n - 1][m - 1];
}
