#include <bits/stdc++.h>
#define ll long long
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define pii pair<int,int>
#define vpii vector<pii>
#define endl '\n'
#define inf (int)1e9
#define infLL (ll)1e18
#define _sort(a) sort(a.begin(), a.end())
#define bsUp(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
#define bsLow(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define rev(a) reverse(a.begin(), a.end())
#define all(a) a.begin(), a.end()
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
// #define int ll
// #include "/home/phamngocthi/cp/see.cpp"
using namespace std;

struct fwt { //sử dụng cho mảng bắt đầu index từ 0, truy vấn cũng từ 0 
    vt bit;
    int n;

    void init(int _n) {
        n = _n;
        bit.assign(n + 2, 0);
    }

    void update(int x, int val) {
        for(int i = x + 1; i <= n; i += i & -i)
            bit[i] += val;
    }

    void update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }

    int get(int x) {
        int res = 0;
        for(int i = x + 1; i >= 1; i -= i & -i)
            res += bit[i];
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} ft;

struct fwt { //sử dụng cho mảng bắt đầu index từ 1, truy vấn cũng từ 1
    vt bit;
    int n;

    fwt(vt &a) {
        n = a.size() - 1;
        bit.assign(n + 1, 0);
        for(int i = 1; i <= n; i++)
            update(i, a[i]);
    }

    void update(int x, int val) {
        for(int i = x; i <= n; i += i & -i)
            bit[i] += val;
    }

    void update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }

    int get(int x) {
        int res = 0;
        for(int i = x; i >= 1; i -= i & -i)
            res += bit[i];
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

struct FT {
    int n;
    vt bit;

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
        int res = 0;
        for(int i = x + 1; i >= 1; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }

    int get(int l, int r) {
        if(l > r)
            return 0;
        return get(r) - get(l - 1);
    }
};

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int cnt = n * m; //count char '*'
    vt idx(cnt + 1, 0);
    for(int i = 0; i < n; i++) {
        string c;
        cin >> c;
        for(int j = 0; j < m; j++) 
            if(c[j] == '.') {
                idx[j * n + i + 1] = 1;
                cnt--;
            } else idx[j * n + i + 1] = 0;
    }
    fwt ft(idx);
    while(q--) {
        int x, y;
        cin >> x >> y;
        int id = (y - 1) * n + x;
        if(idx[id]) {
            idx[id] = 0;
            cnt++;
            ft.update(id, -1);
        } else {
            idx[id] = 1;
            ft.update(id, 1);
            cnt--;
        }
        cout << ft.get(cnt) << endl;
    }
    return 0;
}
