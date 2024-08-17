#include <bits/stdc++.h>
#define int long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)2e5, K = 20;
vector<int> adj[N];
int d[N], p[N][K + 1];
bool vis[N];
int n;
map<int,int> c1[N], c2[N];

void bfs() {
	queue<int> q;
	q.push(0);
	vis[0] = true;
	d[0] = 1;
	p[0][0] = 0;
	while(q.size()) {
		int u = q.front();
		q.pop();
		for(int v : adj[u]) {
			if(vis[v] == false) {
				d[v] = d[u] + 1;
				p[v][0] = u;
				for(int i = 1; i < K; i++) {
					p[v][i] = p[p[v][i - 1]][i - 1];
				}
				q.push(v);
				vis[v] = true;
			}
		}
	}
}

int lca(int u, int v) {
	if(d[u] < d[v]) {
		swap(u, v);
	}
	for(int i = K - 1; i >= 0; i--) {
		if(d[p[u][i]] >= d[v]) {
			u = p[u][i];
		}
	}
	if(u == v) {
		return u;
	}
	for(int i = K - 1; i >= 0; i--) {
		if(p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	}
	return p[u][0];
}

int um[N];
int ans = 0;

void dfs(int u, int p) {
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
			um[u] += um[v];
        }
    }
	for(int v : adj[u]) {
		if(v != p) {
			ans += min(um[v] * c1[u][v], c2[u][v]);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		cin >> c1[u][v] >> c2[u][v];
		c1[v][u] = c1[u][v];
		c2[v][u] = c2[u][v];
	}
	bfs();
	for(int i = 0; i < n - 1; i++) {
		int l = lca(i, i + 1);
		um[i]++;
		um[i + 1]++; 
		um[l] -= 2;
	}
	dfs(0, -1);
	cout << ans;
	return 0;
}