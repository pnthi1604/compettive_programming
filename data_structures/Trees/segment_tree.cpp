#include <bits/stdc++.h>
#define ll long long
#define infInt (int)1e9 + 1
// #define infLL 0x3f3f3f3f3f3f
#define infLL (int)1e18
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define vtttt vector<vttt>
#define pii pair<int, int>
#define vpii vector<pii>
#define endl '\n'
#define all(a) a.begin(), a.end()
#define _sort(a) sort(all(a))
#define bsUp(a, x) upper_bound(all(a), x) - a.begin()
#define bsLow(a, x) lower_bound(all(a), x) - a.begin()
#define rev(a) reverse(all(a))
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define int ll
// #include "/home/phamngocthi/cp/see.cpp"
using namespace std;

struct segtree {
    int n;
    vt t;
    vt a;

    segtree(vt &arr) {
        n = arr.size();
        t.resize(4 * n);
        a.assign(all(arr));
        build(1, 0, n - 1);
    }

    int combine(int a, int b) {
        return min(a, b);
    }

    void combine(int id) {
        t[id] = combine(t[id * 2], t[id * 2 + 1]);
    }

    void build(int id, int l, int r) {
        if(l == r)
            t[id] = a[l];
        else {
            int m = (l + r) / 2;
            build(2 * id, l, m);
            build(2 * id + 1, m + 1, r);
            combine(id);
        }
    }

    void update(int id, int l, int r, int i, int val) {
        if(l > i || r < i)
            return;
        if(l == r)
            t[id] = val, a[i] = val;
        else {
            int m = (l + r) / 2;
            update(id * 2, l, m, i, val);
            update(id * 2 + 1, m + 1, r, i, val);
            combine(id);
        }
    }

    void update(int id, int val) {
        update(1, 0, n - 1, id, val);
    }

    int get(int id, int l, int r, int u, int v) {
        if(l > v || r < u)
            return 0;
        if(l >= u && r <= v)
            return t[id];
        int m = (l + r) / 2;
        int get1 = get(id * 2, l, m, u, v);
        int get2 = get(id * 2 + 1, m + 1, r, u, v);
        return combine(get1, get2);
    }

    int get(int u, int v) {
        return get(1, 0, n - 1, u, v);
    }
};

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vt a(n);
    for(int &x : a)
        cin >> x;
    segtree st;
    st.init(a);
    int t; cin >> t;
    while(t--) {
        int type; cin >> type;
        if(type == 1) {
            int id, val; cin >> id >> val;
            id--;
            st.update(id, val);
        } else {
            int l, r; cin >> l >> r;
            l--, r--;
            cout << st.get(l, r) << endl;
        }
    }
}












