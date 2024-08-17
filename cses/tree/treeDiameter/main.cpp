#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)2e5;
int n;
vector<int> adj[N];
int d[N], vis[N];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 1;
    auto dfs = [&](auto dfs, int u) -> int {
        vis[u] = 1;
        d[u] = 1;
        vector<int> set_v;
        for(int v : adj[u]) {
            if(vis[v]) continue;
            set_v.push_back(v);
            d[u] = max(d[u], dfs(dfs, v) + 1);
        }
        int mx1 = 1, mx2 = 1;
        for(int v : set_v) {
            if(mx1 == d[v] + 1)
                mx2 = d[v] + 1;
            else if(mx1 < d[v] + 1) 
                mx2 = mx1, mx1 = d[v] + 1;
            else
                mx2 = max(mx2, d[v] + 1);
        }
        ans = max({ans, mx1 + mx2 - 1, d[u]});
        return d[u];
    };
    dfs(dfs, 0);
    cout << ans - 1;
    return 0;
}