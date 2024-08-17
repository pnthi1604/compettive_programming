#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";

using namespace std;

const int MOD = (int)1e9 + 7;
const int N = 1000;
vector<int> adj[N];
int n, t;
int h[N];
pair<int,int> a[N][N];
bool vis[N];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto bfs = [&](int s, int t) -> void {
        queue<pair<int,pair<int,int>>> q;
        q.push({s, {h[s], 0}});
        for(int i = 0; i < n; i++) vis[i] = false;
        vis[s] = true;
        while(q.size()) {
            auto x = q.front();
            q.pop();
            int u = x.first;
            int hu = x.second.first;
            int du = x.second.second;
            for(int v : adj[u]) {
                if(vis[v]) continue;
                int hv = max(hu, h[v]);
                int dv = du + 1;
                if(v == t) {
                    a[s][t] = a[t][s] = {hv, dv};
                    return;
                }
                q.push({v, {hv, dv}});
                vis[v] = true;
            }
        }
    };
    for(int u = 0; u < n; u++) {
        for(int v = u + 1; v < n; v++) {
            bfs(u, v);
        }
    }
    ll ans = 0;
    for(int x = 0; x < n; x++) {
        for(int y = x + 1; y < n; y++) {
            for(int z = y + 1; z < n; z++) {
                auto[hxy, dxy] = a[x][y];
                auto[hyz, dyz] = a[y][z];
                auto[hzx, dzx] = a[z][x];
                int hxyz = max({hxy, hyz, hzx});
                int dxyz = dxy + dyz + dzx;
                if(hxyz == t) ans = (ans + dxyz) % MOD;
            }
        }
    }
    cout << ans % MOD;
    return 0;
}