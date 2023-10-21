#include <bits/stdc++.h>
#define int long long
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define ii pair<int,int>
#define vii vector<ii>
#define endl '\n'
#define _sort(a) sort(a.begin(), a.end())
#define bsUp(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
#define bsLow(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define rev(a) reverse(a.begin(), a.end())
#define all(a) a.begin(), a.end()
#define inf (int)1e18
using namespace std;

struct fwt {
    vt bit;
    int n;

    void init(vt &a) {
        n = a.size();
        bit.assign(n, 0);
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

signed main() {
//   ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vt a(n);
    for(int &x : a)
        cin >> x;
    fwt ft;
    ft.init(vt((int)1e7));
}
