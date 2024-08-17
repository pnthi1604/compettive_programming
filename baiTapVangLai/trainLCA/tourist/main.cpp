#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)1e5, K = log2(N) + 2;
int p[N][K + 1], d[N];
vector<int> adj[N];
int n;

void bfs() {
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    d[0] = 1;
    p[0][0] = 0;
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(vis[v] == false) {
                d[v] = d[u] + 1;
                p[v][0] = u;
                for(int i = 1; i < K; i++) {
                    p[v][i] = p[p[v][i - 1]][i - 1];
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
    for(int i = K - 1; i >= 0; i--) {
        if(d[p[u][i]] >= d[v]) {
            u = p[u][i];
        }
    }
    if(u == v) {
        return u;
    }
    for(int i = K - 1; i >= 0; i--) {
        if(p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

int dist(int u, int v) {
    return d[u] + d[v] - 2 * d[lca(u, v)] + 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int j = 2;
        while(j * i <= n) {
            ans += dist(i - 1, i * j - 1);
            j++;
        }
    }
    cout << ans;
    return 0;
}