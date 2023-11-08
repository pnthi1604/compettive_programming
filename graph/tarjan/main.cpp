#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<vector<int>> adj;
int timer;
vector<int> low, num, stack;

void tarjan(int u, int p) {
	num[u] = low[u] = ++timer;
	stack.push_back(u);
	for(int v : adj[u]) {
		if(v == p) {
			continue;
		}
		if(num[v] == 0) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], num[v]);
		}
	}
	if(num[u] == low[u]) {
		cntComp++;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}