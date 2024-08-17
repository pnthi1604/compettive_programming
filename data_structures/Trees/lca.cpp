#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

int n, q;

struct LCA {
    int n, K;
    vector<vector<int>> adj, up;
    vector<int> depth;

    void init(vector<vector<int>> &a) {
        adj = a;
        n = adj.size();
        K = log2(n) + 1;
        up.assign(n, vector<int>(K + 1, 0));
        depth.resize(n);
        bfs();
    }

    void bfs() {
        queue<int> q;
        q.push(0);
        vector<bool> vis(n, false);
        vis[0] = true;
        up[0][0] = 0;
        while(q.size()) {
            int u = q.front();
            q.pop();
            for(int v : adj[u]) {
                if(vis[v] == false) {
                    depth[v] = depth[u] + 1;
                    up[v][0] = u;
                    for(int i = 1; i < K; i++) {
                        up[v][i] = up[up[v][i - 1]][i - 1];
                    }
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }

    int lca(int u, int v) {
        if(depth[u] < depth[v]) {
            swap(u, v);
        }
        for(int i = K - 1; i >= 0; i--) {
            if(depth[up[u][i]] >= depth[v]) {
                u = up[u][i];
            }
        }
        if(u == v) {
            return u;
        }

        for(int i = K - 1; i >= 0; i--) {
            if(up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 2; i <= n; i++) {
        int j;
        cin >> j;
        adj[j - 1].push_back(i - 1);
    }
    LCA t;
    t.init(adj);
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << t.lca(u - 1, v - 1) + 1 << endl;
    }
}