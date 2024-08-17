#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";

using namespace std;

vector<vector<int>> adj, T;
vector<int> depth;
int k;

void bfs() {
    vector<bool> vis(adj.size(), false);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    depth[1] = 1;
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(vis[v] == false) {
                depth[v] = depth[u] + 1;
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
    if(depth[u] < depth[v]) {
        swap(u, v);
    }
    for(int i = k - 1; i >= 0; i--) {
        if(depth[T[u][i]] >= depth[v]) {
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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    adj.resize(n + 1);
    for(int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    k = log2(n) + 1;
    depth.resize(n + 1);
    T.assign(n + 1, vector<int>(k + 1));
    bfs();
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}