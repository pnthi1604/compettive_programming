#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define hi cerr << "HIHIHI" << endl;

using namespace std;

const int N = (int)1e5;
vector<int> adj[N];
int sz[N], color[N], cnt[N], ans[N];
int n;
bool big[N];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> color[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](auto dfs, int u, int p) -> void {
        sz[u] = 1;
        for(int v : adj[u]) {
            if(v == p) continue;
            dfs(dfs, v, u);
            sz[u] += sz[v];
        }
    };

    auto add = [&](auto add, int u, int p, int del) -> void {
        int c = color[u];
        cnt[c] += del;
        for(int v : adj[u]) {
            if(v == p || big[v]) continue;
            add(add, v, u, del);
        }
    };

    auto dsu_on_tree = [&](auto dsu_on_tree, int u, int p, int keep) -> void {
        int b = -1;
        // tim big child
        for(int v : adj[u]) {
            if(v != p && (b == -1 || sz[b] < sz[v])) {
                b = v;
            }
        }
        // tra loi truy van cho cac nut v khong phai big child
        for(int v : adj[u]) {
            if(v != p && v != b) {
                dsu_on_tree(dsu_on_tree, v, u, 0);
            }
        } // xoa thong tin nut v de khong bi de thong tin len cac nut khac
    
        if(b != -1) {
            big[b] = true;
            // tra loi truy van cho big child
            dsu_on_tree(dsu_on_tree, b, u, 1); // giu lai thong tin cua big child de tra loi cho nut u
        }

        add(add, u, p, 1);

        ans[u] = cnt[0];

        if(b != -1)
            big[b] = false;
        if(!keep)
            add(add, u, p, -1);
    };

    dsu_on_tree(dsu_on_tree, 0, -1, 0);
    for(int i = 0; i < n; i++)
        cout << "ans[" << i + 1 << "] = " << ans[i] << endl;
    return 0;
}