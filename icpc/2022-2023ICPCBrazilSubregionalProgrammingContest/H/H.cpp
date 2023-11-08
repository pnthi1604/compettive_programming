#include <bits/stdc++.h>
#define int long long
#define hi cerr << "HIHIHI\n";

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> adjTwoWay;
vector<int> num, low;
vector<bool> used;
vector<int> stackDfs;
vector<int> stackTarjan;
vector<int> in, out;
int timer;

// void dfs(int u, vector<vector<int>> &adj) {
// 	used[u] = true;
// 	stackDfs.push_back(u);
// 	for(int v : adj[u]) {
// 		if(used[v] == false) {
// 			dfs(v, adj);
// 		}
// 	}
// }

void tarjan(int u, vector<vector<int>> &adj, int &cntCompOneWay) {
	num[u] = low[u] = ++timer;
	stackTarjan.push_back(u);
	for(int v : adj[u]) {
		if(num[v] == 0) {
			tarjan(v, adj, cntCompOneWay);
			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], low[v]);
		}
	}
	if(num[u] == low[u]) {
		cntCompOneWay++;
		int start = stackTarjan.back();
		vector<int> vertexs;
		while(start != u) {
			vertexs.push_back(start);
			stackTarjan.pop_back();
			start = stackTarjan.back();
		}
		vertexs.push_back(start);
		
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	adjTwoWay.resize(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adjTwoWay[u].push_back(v);
		adjTwoWay[v].push_back(u);
	}
	num.resize(n);
	low.resize(n);
	used.resize(n);
	int cntCompOneWay = 0, cntComTwoWay = 0;
	for(int i = 0; i < n; i++) {
		// if(used[i] == false) {
		// 	dfs(i, adjTwoWay);
		// 	cntComTwoWay++;
		// 	int cnt = 0;
		// 	for(int v : stackDfs) {
		// 		if(num[v] == 0) {
		// 			tarjan(v, adj, cnt);
		// 		}
		// 	}
		// 	cntCompOneWay += (cnt - 1);
		// 	stackDfs.clear();
		// }'
		if(num[i] == 0) {
			int cnt = 0;
			tarjan(i, adj, cnt);
		}
	}
	// cerr << "cntCompOneWay = " << cntCompOneWay << endl;
	// cerr << "cntComTwoWay = " << cntComTwoWay << endl;
	// cout << (cntComTwoWay - 1) * 2 + cntCompOneWay;
}