#include <bits/stdc++.h>
#define int long long
#define hi cout << "hi\n";

using namespace std;

int k, n;

void dfs(vector<vector<int>> &adj, vector<int> &depth, int u, int p) {
	for(int v : adj[u]) {
		if(v != p) {
			if(u != -1)
				depth[v] = depth[u] + 1;
			else
				depth[v] = 1;
			dfs(adj, depth, v, u);
		}
	}
}

void find(int &maxDepth, int &maxU, vector<int> &depth, vector<bool> &mark) {
	for(int i = 0; i < n; i++) {
		if(mark[i] && maxDepth < depth[i]) {
			maxDepth = depth[i];
			maxU = i;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		vector<vector<int>> adj(n, vector<int>());
		vector<bool> mark(n);
		for(int i = 0; i < k; i++) {
			int u;
			cin >> u;
			u--;
			mark[u] = true;
		}
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if(k == 1) {
			cout << 0 << '\n';
			continue;
		}
		int isMark;
		for(int i = 0; i < n; i++)
			if(mark[i]) {
				isMark = i;
				break;
			}
		vector<int> depth(n);
		dfs(adj, depth, isMark, -1);
		int maxDepth = 0, maxU;
		find(maxDepth, maxU, depth, mark);
		for(int &x : depth)
			x = 0;
		dfs(adj, depth, maxU, -1);
		find(maxDepth, maxU, depth, mark);
		cout << (maxDepth + 1) / 2 << '\n';
	}
}