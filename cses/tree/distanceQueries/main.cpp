#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

struct LCA {
    int n, k;
    vector<vector<int>> adj, T;
    vector<int> d;

    void init(vector<vector<int>> &a) {
        adj = a;
        n = a.size();
        k = log2(n) + 1;
        T.assign(n, vector<int>(k + 1));
        d.resize(n);
        bfs();
    }

    void bfs() {
        queue<int> q;
        q.push(0);
        vector<bool> vis(n, false);
        vis[0] = true;
        d[0] = 0;
        T[0][0] = 0;
        while(q.size()) {
            int u = q.front();
            q.pop();
            for(int v : adj[u]) {
                if(vis[v] == false) {
                    d[v] = d[u] + 1;
                    T[v][0] = u;
                    for(int i = 1; i < k; i++) {
                        T[v][i] = T[T[v][i - 1]][i - 1];
                    }
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }

    int lca(int u, int v) {
        if(d[u] < d[v]) {
            swap(u, v);
        }
        for(int i = k - 1; i >= 0; i--) {
            if(d[T[u][i]] >= d[v]) {
                u = T[u][i];
            }
        }
        if(u == v) {
            return u;
        }
        for(int i = k - 1; i >= 0; i--) {
            if(T[u][i] != T[v][i]) {
                u = T[u][i];
                v = T[v][i];
            }
        }
        return T[u][0];
    }

    int dist(int u, int v) {
        return d[u] + d[v] - 2 * d[lca(u, v)];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA t;
    t.init(adj);
    while(q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << t.dist(u, v) << endl;
    }
}