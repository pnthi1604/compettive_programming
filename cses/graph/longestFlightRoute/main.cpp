#include <bits/stdc++.h>
#define ll long long
#define int long long
#define hi cerr << "HIHIHI\n";
using namespace std;

const int maxn = (int)1e5, maxm = (int)2e5;
vector<int> adj[maxn];
vector<int> topo, dist(maxn, 1), par(maxn, -1);
vector<bool> used(maxn);

void dfs(int u) {
    used[u] = true;
    for(int v : adj[u]) {
        if(used[v] == false)
            dfs(v);
    }
    topo.push_back(u);
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    dfs(0);
    reverse(topo.begin(), topo.end());
    for(int u : topo) {
        for(int v : adj[u]) {
            if(dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
        }
    }
    if(dist[n - 1] < 2) {
        cout << "IMPOSSIBLE";
    } else {
        vector<int> res;
        int start = n - 1;
        while(start != 0) {
            res.push_back(start + 1);
            start = par[start];
        }
        res.push_back(1);
        reverse(res.begin(), res.end());
        cout << res.size() << '\n';
        for(int x : res)
            cout << x << ' ';
    }
}
