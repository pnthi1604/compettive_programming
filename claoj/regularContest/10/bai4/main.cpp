#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define hi cerr << "HIHIHI" << endl;

using namespace std;

const int N = (int)2e5;

struct DSU {
    int n;
    vector<int> par, sz;
    void init(int _n) {
        n = _n + 1;
        par.resize(n + 1);
        sz.resize(n + 1);
        for(int i = 1; i <= n; i++)
            par[i] = i, sz[i] = 1;
    }
    int f(int x) {
        if(x == par[x]) return x;
        return par[x] = f(par[x]);
    }
    bool same(int x, int y) {
        return f(x) == f(y);
    }
    bool U(int x, int y) {
        if(same(x, y)) return false;
        x = f(x), y = f(y);
        if(sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        return true;
    }
    vector<vector<int>> gr() {
        vector<vector<int>> g(n + 1, vector<int>());
        for(int i = 1; i <= n; i++) 
            g[f(i)].push_back(i);
        return g;
    }
};
DSU dt1, dt2;
int have_a[N], have_b[N];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, w, na, nb;
    cin >> n >> m >> w >> na >> nb;
    dt1.init(n);
    dt2.init(n);
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        if(c > w) continue;
        if(c < w) dt1.U(u, v);
        dt2.U(u, v);
    }
    for(int i = 0; i < na; i++) {
        int x; cin >> x;
        have_a[x] = 1;
    }
    for(int i = 0; i < nb; i++) {
        int x; cin >> x;
        have_b[x] = 1;
    }
    ll ans1 = 0, ans2 = 0;
    vector<vector<int>> gr1 = dt1.gr(), gr2 = dt2.gr();
    for(int i = 1; i <= n; i++) {
        ll cnt_a = 0, cnt_b = 0;
        for(int x : gr1[i]) {
            cnt_a += have_a[x];
            cnt_b += have_b[x];
        }
        ans1 += cnt_a * cnt_b;
        cnt_a = cnt_b = 0;
        for(int x : gr2[i]) {
            cnt_a += have_a[x];
            cnt_b += have_b[x];
        }
        ans2 += cnt_a * cnt_b;
    }
    cout << ans2 - ans1;
    return 0;
}
