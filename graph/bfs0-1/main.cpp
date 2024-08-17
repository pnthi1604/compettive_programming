#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)2e5;
const int INF = (int)1e9;
int n, m;
vector<pair<int,int>> adj[N];
int d[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	auto bfs0_1 = [&](int s) -> void {
		for(int i = 0; i < n; i++) d[i] = INF;
		d[s] = 0;
		deque<int> q;
		q.push_front(s);
		while(q.size()) {
			int u = q.front();
			q.pop_front();
			for(auto[v, wv] : adj[u]) {
				if(d[v] > d[u] + wv) {
					d[v] = d[u] + wv;
					if(wv == 0)
						q.push_front(v);
					else q.push_back(v);
				}
			}
		}
	};
	bfs0_1(0);
	for(int i = 0; i < n; i++)
		cout << "d[" << i + 1 << "] = " << d[i] << endl;
	return 0;
}