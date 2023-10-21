//https://codeforces.com/gym/103373/problem/F
#include <bits/stdc++.h>
#define int long long
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define pii pair<int,int>
#define vpii vector<pii>
#define endl '\n'
#define _sort(a) sort(a.begin(), a.end())
#define bsUp(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
#define bsLow(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define rev(a) reverse(a.begin(), a.end())
#define all(a) a.begin(), a.end()
#define inf (int)1e18
#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))
using namespace std;

struct node {
    int pre, suf, bitPre, bitSuf, cntSub, range;
};

struct segtree {
    int n;
    vt a;
    vector<node> t;
    vt lz;

    void init(vt arr) {
        n = arr.size();
        a.assign(all(arr));
        t.resize(4 * n);
        lz.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    node combine(node &a, node &b) {
        if(a.range == 0)
            return b;
        if(b.range == 0)
            return a;
        node c;
        c.range = a.range + b.range;
        c.bitPre = a.bitPre;
        c.bitSuf = b.bitSuf;
        c.cntSub = a.cntSub + b.cntSub;
        c.pre = a.pre;
        c.suf = b.suf;
        if(a.bitSuf != b.bitPre) {
            c.cntSub += a.suf * b.pre;
            if(a.pre == a.range)
                c.pre += b.pre;
            if(b.suf == b.range)
                c.suf += a.suf;
        }
        return c;
    }

    void combine(int id) {
        t[id] = combine(t[id * 2], t[id * 2 + 1]);
    }

    void build(int id, int l, int r) {
        if(l == r) {
            t[id] = {1, 1, a[l], a[l], 1, 1};
        } else {
            int m = (l + r) / 2;
            build(id * 2, l, m);
            build(id * 2 + 1, m + 1, r);
            combine(id);
        }
    }

    void fix(int id, int l, int r) {
        if(lz[id] == 0)
            return;
        t[id].bitPre = 1 - t[id].bitPre;
        t[id].bitSuf = 1 - t[id].bitSuf;
        if(l != r) {
            lz[id * 2] = 1 - lz[id * 2];
            lz[id * 2 + 1] = 1 - lz[id * 2 + 1];
        }
        lz[id] = 0;
    }

    void update(int id, int l, int r, int u, int v) {
        fix(id, l, r);
        if(l > v || r < u)
            return;
        if(l >= u && r <= v) {
            lz[id] = 1;
            fix(id, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(id * 2, l, m, u, v);
        update(id * 2 + 1, m + 1, r, u, v);
        combine(id);
    }

    void update(int l, int r) {
        update(1, 0, n - 1, l, r);
    }

    node get(int id, int l, int r, int u, int v) {
        fix(id, l, r);
        if(l > v || r < u)
            return {0, 0, 0, 0, 0};
        if(l >= u && r <= v)
            return t[id];
        int m = (l + r) / 2;
        node get1 = get(id * 2, l, m, u, v);
        node get2 = get(id * 2 + 1, m + 1, r, u, v);
        return combine(get1, get2);
    }

    int get(int l, int r) {
        return get(1, 0, n - 1, l, r).cntSub;
    }
};

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vt a(n);
    for(int &x : a)
        cin >> x;
    segtree st;
    st.init(a);
    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        if(t == 1) {
            int l, r; cin >> l >> r;
            if(l > r)
                continue;
            st.update(l - 1, r - 1);
        } else {
            int l, r; cin >> l >> r;
            if(l > r)
                continue;
            cout << st.get(l - 1, r - 1) << endl;
        }
    }
}