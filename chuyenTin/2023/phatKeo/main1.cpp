#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    struct FT {
        vector<ll> bit;
        int n;
        void init(int _n) {
            n = _n;
            bit.assign(n + 1, 0);
        }
        void add(int x, int val) {
            for(int i = x + 1; i <= n; i += i & -i)
                bit[i] += val;
        }
        ll get(int x) {
            ll res = 0;
            for(int i = x + 1; i >= 1; i -= i & -i)
                res += bit[i];
            return res;
        }
        ll get(int l, int r) {
            return get(r) - get(l - 1);
        }
    };
    FT ft[10];
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < 10; i++) ft[i].init(n);
    vector<int> a(n);
    for(int &x : a) cin >> x;
    auto check = [&](int pos, int k) -> bool {
        if(k == 0) return true;
        bool ok = (pos % k == 0);
        while(pos) {
            int r = pos % 10;
            pos /= 10;
            if(r == k) ok = true;
        }
        return ok;
    };
    for(int i = 0; i < n; i++) {
        int pos = i + 1;
        for(int k = 0; k < 10; k++) {
            if(check(pos, k)) 
                ft[k].add(i, a[i]);
        }
    }
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int pos, val;
            cin >> pos >> val;
            for(int k = 0; k < 10; k++) {
                if(check(pos, k)) {
                    ft[k].add(pos - 1, -a[pos - 1]);
                    ft[k].add(pos - 1, val);
                }
            }
            a[pos - 1] = val;
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            l--, r--;
            cout << ft[0].get(l, r) + ft[k].get(l, r) << '\n';
        }
    }
    return 0;
}