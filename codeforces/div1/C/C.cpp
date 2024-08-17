#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)1e5, K = log2(N) + 2;
vector<int> adj[N];
int d[N], p[N][K + 1], vis[N];
int n, k;
int cnt[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<pair<int,int>> qs;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        qs.push_back({u, v});
    }

    auto bfs = [&]() -> void {
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        d[0] = 1;
        p[0][0] = 0;
        while(q.size()) {
            int u = q.front();
            q.pop();
            for(int v : adj[u]) {
                if(vis[v]) continue;
                d[v] = d[u] + 1;
                p[v][0] = u;
                for(int i = 1; i < K; i++) {
                    p[v][i] = p[p[v][i - 1]][i - 1];
                }
                q.push(v);
                vis[v] = 1;
            }
        }
    };
    bfs();
        
    auto lca = [&](int u, int v) -> int {
        if(d[u] < d[v]) swap(u, v);
        for(int i = K - 1; i >= 0; i--) {
            if(d[p[u][i]] >= d[v]) {
                u = p[u][i];
            }
        }
        if(u == v) 
            return u;
        for(int i = K - 1; i >= 0; i--) {
            if(p[u][i] != p[v][i]) {
                u = p[u][i];
                v = p[v][i];
            }
        }
        return p[u][0];
    };

    cin >> k;
    while(k--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int l = lca(a, b);
        cnt[a]++;
        cnt[b]++;
        cnt[l] -= 2;
    }

    auto dfs = [&](auto &&dfs, int u, int p = -1) -> void {
        for(int v : adj[u]) {
            if(v == p) continue;
            dfs(dfs, v, u);
            cnt[u] += cnt[v];
        }
    };
    dfs(dfs, 0);
    
    for(auto[u, v] : qs) {
        cout << (p[u][0] == v ? cnt[u] : cnt[v]) << ' ';
    }
    return 0;
}