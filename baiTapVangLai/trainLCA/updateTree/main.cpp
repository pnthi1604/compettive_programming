#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'
 
using namespace std;
 
const int N = (int)2e5;
const int K = log2(N + 1);
int n, q;
vector<int> adj[N + 1];
int d[N + 1], p[N + 1][K + 1];
 
void bfs() {
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    d[0] = 1;
    p[0][0] = 0;
    vis[0] = true;
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
 
int cnt[N + 1], cntlca[N + 1], um[N + 1];
 
int dfs(int u, int p) {
    cnt[u] = um[u];
    for(int v : adj[u]) {
        if(v != p) {
            cnt[u] += dfs(v, u);
        }
    }
    return cnt[u];
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        adj[i].clear();
        cin >> um[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    cin >> q;
    while(q--) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        int l = lca(u, v);
        um[u] += x;
        um[v] += x;
        um[l] -= 2 * x;
        cntlca[l] += x;
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++) {
        cout << cnt[i] + cntlca[i] << ' ';
    }
}