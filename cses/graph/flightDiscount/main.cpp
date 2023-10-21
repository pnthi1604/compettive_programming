#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int inf = (int)1e18;
const int maxn = (int)1e5, maxm = (int)2e5;
int n, m;
vector<pair<int, int>> adj[maxn];
vector<int> dist1(maxn, inf), dist2(maxn, inf);
 
struct cmp {
	bool operator()(const int &a, const int &b) const {
		if(dist1[a] != dist1[b])
			return dist1[a] < dist1[b];
		if(dist2[a] != dist2[b])
			return dist2[a] < dist2[b];
		return a < b;
	}
};

void add(multiset<int,cmp> &ms, int v) {
	if(ms.find(v) != ms.end())
		ms.erase(ms.find(v));
	ms.insert(v);
}
 
void dj() {
	multiset<int,cmp> ms;
	ms.insert(0);
	dist1[0] = dist2[0] = 0;
	while(ms.size()) {
		int u = *ms.begin();
		ms.erase(ms.begin());
		for(auto[w, v] : adj[u]) {
			if(dist1[v] > dist1[u] + w) {
				dist1[v] = dist1[u] + w;
				add(ms, v);
			}
			if(dist2[v] > min(dist2[u] + w, dist1[u] + w / 2)) {
				dist2[v] = min(dist2[u] + w, dist1[u] + w / 2);
				add(ms, v);
			}
		}
	}
	cout << dist2[n - 1];
}
 
signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		adj[u].push_back({c, v});
	}
	dj();
}