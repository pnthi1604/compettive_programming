#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    struct ST {
        vector<ll> t;
        int n;
        void init(int _n) {
            n = _n;
            t.assign(n * 4, 0);
        }
        void update(int id, int l, int r, int i, int val) {
            if(l > i || r < i) return;
            if(l == r) {
                t[id] = val;
                return;
            }
            int m = (l + r) / 2;
            update(id * 2, l, m, i, val);
            update(id * 2 + 1, m + 1, r, i, val);
            combine(id);
        }
        ll combine(ll a, ll b) {
            return a + b;
        }
        void combine(int id) {
            t[id] = combine(t[id * 2], t[id * 2 + 1]);
        }
        void update(int i, int val) {
            update(1, 0, n - 1, i, val);
        }
        ll get(int id, int l, int r, int u, int v) {
            if(l > v || r < u) return 0;
            if(l >= u && r <= v) return t[id];
            int m = (l + r) / 2;
            ll get1 = get(id * 2, l, m, u, v);
            ll get2 = get(id * 2 + 1, m + 1, r, u, v);
            return combine(get1, get2);
        }
        ll get(int l, int r) {
            return get(1, 0, n - 1, l, r);
        }
    };
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    ST st[10];
    for(int i = 0; i < 10; i++) st[i].init(n);
    for(int i = 0; i < n; i++)
        st[0].update(i, a[i]);
    auto check = [&](int i, int k) -> bool {
        bool ok = (i % k == 0);
        int tmp_i = i;
        while(tmp_i) {
            int r = tmp_i % 10;
            tmp_i /= 10;
            if(r == k) ok = true;
        }
        return ok;
    };
    for(int k = 1; k < 10; k++) {
        for(int i = 0; i < n; i++) {
            int pos = i + 1;
            if(check(pos, k)) {
                st[k].update(i, a[i]);
            }
        }
    }
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int pos, c;
            cin >> pos >> c;
            a[pos - 1] = c;
            st[0].update(pos - 1, a[pos - 1]);
            for(int k = 1; k < 10; k++) {
                if(check(pos, k))
                    st[k].update(pos - 1, a[pos - 1]);
            }
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            l--, r--;
            cout << st[0].get(l, r) + st[k].get(l, r) << '\n';
        }
    }
    return 0;
}