#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)3e5 + 1, K = log2(N) + 2;
vector<int> adj[N];
int p[N][K + 1], d[N], S[N];
bool vis[N];
int n;

void bfs() {
    queue<int> q;
    q.push(0);
    vis[0] = true;
    p[0][0] = 0;
    d[0] = 1;
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

int findP(int u, int s) {
    for(int i = K - 1; i >= 0; i--) {
        if(S[p[u][i]] <= s) {
            u = p[u][i];
        }
    }
    if(S[u] < s) {
        return u;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> S[0];
    for(int i = 1; i <= n; i++) {
        cin >> S[i];
        int par;
        cin >> par;
        adj[par].push_back(i);
        adj[i].push_back(par);
    }
    bfs();
    for(int i = 1; i <= n; i++) {
        int an = findP(i, S[i]);
        if(an == -1) {
            cout << 0 << endl;
        } else {
            cout << d[i] - d[an] << endl;
            S[an] = S[i];
        }
    }
    return 0;
}