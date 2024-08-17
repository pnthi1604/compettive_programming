#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'
 
using namespace std;
 
const int N = (int)2e5;
int n;
vector<int> adj[N];
int ans[N], se[N], fi[N];
 
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
    auto dfs1 = [&](auto dfs1, int u, int p) -> void {
        se[u] = 0;
        fi[u] = 0;
        for(int v : adj[u]) {
            if(v == p) continue;
            dfs1(dfs1, v, u);
            if(fi[v] + 1 > fi[u]) {
                se[u] = fi[u];
                fi[u] = fi[v] + 1;
            } else if(fi[v] + 1 > se[u]) {
                se[u] = fi[v] + 1;
            }
        }
    };
    dfs1(dfs1, 0, -1);
    auto dfs2 = [&](auto dfs2, int u, int p) -> void {
        for(int v : adj[u]) {
            if(v == p) continue;
            if(fi[v] != fi[u] - 1) {
                if(fi[u] + 1 > fi[v]) {
                    se[v] = fi[v];
                    fi[v] = fi[u] + 1;
                } else if(fi[u] + 1 == fi[v]) {
                    se[v] = fi[v];
                }
            } else {
                if(se[u] + 1 > fi[v]) {
                    se[v] = fi[v];
                    fi[v] = se[u] + 1;
                } else if(se[u] + 1 == fi[v]) {
                    se[v] = fi[v];
                }
            }
            dfs2(dfs2, v, u);
        }
    };
    dfs2(dfs2, 0, -1);
    for(int i = 0; i < n; i++) cout << fi[i] << ' ';
    return 0;
}