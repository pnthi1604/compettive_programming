#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)7e4, K = log2(N) + 2;
vector<int> adj[N];
int p[N][K + 1];
int n, q;
int d[N];
bool vis[N];

void bfs() {
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

struct ST {
    int n;
    vector<int> st;

    void init(int _n) {
        n = _n;
        st.resize(4 * n);
        build(1, 0, n - 1);
    }

    int combine(int u, int v) {
        if(u == -1) {
            return v;
        }
        if(v == -1) {
            return u;
        }
        int l = lca(u, v);
        return l;
    }

    void combine(int id) {
        st[id] = combine(st[id * 2], st[id * 2 + 1]);
    }

    void build(int id, int l, int r) {
        if(l == r) {
            st[id] = l;
            return;
        }
        int m = (l + r) / 2;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        combine(id);
    }

    int get(int id, int l, int r, int u, int v) {
        if(l > v || r < u) {
            return -1;
        }
        if(l >= u && r <= v) {
            return st[id];
        }
        int m = (l + r) / 2;
        int get1 = get(id * 2, l, m, u, v);
        int get2 = get(id * 2 + 1, m + 1, r, u, v);
        return combine(get1, get2);
    }

    int get(int u, int v) {
        return get(1, 0, n - 1, u, v);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    ST st;
    st.init(n);
    while(q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << st.get(u, v) + 1 << endl;
    }
    return 0;
}