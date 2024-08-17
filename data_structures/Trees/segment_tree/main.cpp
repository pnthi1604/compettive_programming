#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define hi cerr << "HIHIHI" << endl;

using namespace std;

const int N = (int)1e5;
int n;
int a[N];

struct ST {
    int n;
    vector<ll> t;

    void init(int _n) {
        n = _n;
        t.resize(4 * n);
        build(1, 0, n - 1);
    }

    int combine(int a, int b) {
        return a + b;
    }

    void combine(int id) {
        t[id] = combine(t[id * 2], t[id * 2 + 1]);
    }

    void build(int id, int l, int r) {
        if(l == r) {
            t[id] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        combine(id);
    }

    void update(int id, int l, int r, int i, int val) {
        if(i > r || r < l)
            return;
        if(l == r) {
            t[id] = val;
            a[i] = val;
            return;
        }
        
        int m = (l + r) / 2;
        update(id * 2, l, m, i, val);
        update(id * 2 + 1, m + 1, r, i, val);
        combine(id);
    }

    void update(int i, int val) {
        update(1, 0, n - 1, i, val);
    }

    ll get(int id, int l, int r, int u, int v) {
        if(u > r || v < l)
            return 0;
        if(l >= u && r <= v) 
            return t[id];
        int m = (l + r) / 2;
        ll get1 = get(id * 2, l, m, u, v);
        ll get2 = get(id * 2 + 1, m + 1, r, u, v);
        return combine(get1, get2);
    }

    ll get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    ST st;
    st.init(n);
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        cout << "sum(" << l << ", " << r << ") = " << st.get(l - 1, r - 1) << endl;
    }
    return 0;
}