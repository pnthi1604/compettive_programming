#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)1e5;
struct FT {
    int n;
    vector<int> bit;

    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }

    void add(int x, int val) {
        for(int i = x + 1; i <= n; i += i & -i) {
            bit[i] += val;
        }
    }

    int get(int x) {
        int ans = 0;
        for(int i = x + 1; i >= 1; i -= i & -i) {
            ans += bit[i];
        }
        return ans;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} ft;
vector<vector<int>> adj;
int n, q;
vector<int> p;
vector<int> sz;
vector<bool> big;
vector<string> ans;
vector<int> idV;
struct Query {
    int id, l, r;
};
vector<vector<Query>> qs;

void reset() {
    adj.assign(n, vector<int>());
    qs.assign(n, vector<Query>());
    p.resize(n);
    ans.assign(q, "NO");
    idV.resize(n);
    ft.init(n);
    sz.assign(n, 0);
    big.assign(n, false);
}

void dfs(int u, int p) {
    sz[u] = 1;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

void add(int u, int p, int del) {
    // cerr << "del = " << del << endl;
    // cerr << "u = " << u << endl;
    ft.add(idV[u], del);
    // cerr << ft.get(0, 0) << endl;
    for(int v : adj[u]) {
        if(v != p && big[v] == false) {
            add(v, u, del);
        }
    }
}

void dsuOnTree (int u, int p, int keep) {
    int b = -1;
    for(int v : adj[u]) {
        if(v != p && (b == -1 || sz[v] > sz[b])) {
            b = v;
        }
    }
    for(int v : adj[u]) {
        if(v != p && v != b) {
            dsuOnTree(v, u, 0);
        }
    }
    if(b != -1) {
        big[b] = true;
        dsuOnTree(b, u, 1);
    }
    add(u, p, 1);
    for(auto[id, l, r] : qs[u]) {
        int num = ft.get(l, r);
        if(num >= 1) {
            ans[id] = "YES";
        } else {
            ans[id] = "NO";
        }
    }
    if(b != -1) {
        big[b] = false;
    }
    if(keep == 0) {
        add(u, p, -1);
    }
}

void solve() {
    cin >> n >> q;
    reset();
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        idV[p[i]] = i;
    }
    for(int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        x--;
        l--, r--;
        qs[x].push_back({i, l, r});
    }
    dfs(0, -1);
    dsuOnTree(0, -1, 0);
    for(int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}