#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Node {
    int l1, l2, r1, r2, range;
    bool ok;
};

struct ST {
    string s;
    int n;
    vector<int> lz;
    vector<Node> t;

    void init(string _s) {
        s = _s;
        n = s.length();
        t.resize(4 * n);
        lz.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    Node combine(Node a, Node b) {
        if(a.range == 0)
            return b;
        if(b.range == 0)
            return a;
        Node c = {a.l1, a.l2, b.r1, b.r2, a.range + b.range, true};
        if(a.range == 1) {
            c.l2 = b.l1;
        }
        if(b.range == 1) {
            c.r1 = a.r2;
        }
        c.ok = a.ok && b.ok && (a.r2 != b.l1) && (a.r1 != b.l1) && (a.r2 != b.l2);
        return c;
    }

    void combine(int id) {
        t[id] = combine(t[id * 2], t[id * 2 + 1]);
    }

    void build(int id, int l, int r) {
        if(l == r) {
            int c = s[l] - 'a';
            t[id] = {c, c, c, c, 1, true};
            return;
        }
        int m = (l + r) / 2;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        combine(id);
    }

    void add(int &x, int val) {
        x = (x + val) % 26;
    }

    void fix(int id, int val) {
        if(id >= lz.size())
            return;
        add(t[id].l1, val);
        add(t[id].l2, val);
        add(t[id].r1, val);
        add(t[id].r2, val);
        lz[id] += val;
    }

    void down(int id) {
        fix(id * 2, lz[id]);
        fix(id * 2 + 1, lz[id]);
        lz[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        down(id);
        if(l > v || r < u)
            return;
        if(l >= u && r <= v) {
            fix(id, val);
            return;
        }
        int m = (l + r) / 2;
        update(id * 2, l, m, u, v, val);
        update(id * 2 + 1, m + 1, r, u, v, val);
        combine(id);
    }

    void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    Node get(int id, int l, int r, int u, int v) {
        down(id);
        if(l > v || r < u)
            return {0, 0, 0, 0, 0, false};
        if(l >= u && r <= v) {
            return t[id];
        }
        int m = (l + r) / 2;
        Node get1 = get(id * 2, l, m, u, v);
        Node get2 = get(id * 2 + 1, m + 1, r, u, v);
        return combine(get1, get2);
    }

    int get(int l, int r) {
        return get(1, 0, n - 1, l, r).ok;
    }
};

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        ST st;
        st.init(s);
        for(int i = 0; i < m; i++) {
            int type;
            cin >> type;
            if(type == 1) {
                int l, r, x;
                cin >> l >> r >> x;
                l--, r--;
                st.update(l, r, x);
            } else {
                int l, r;
                cin >> l >> r;
                l--, r--;
                if(st.get(l, r)) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
}