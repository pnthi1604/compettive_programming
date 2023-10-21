// https://codeforces.com/contest/1083/problem/E
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f
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
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define int ll
// #include "/home/phamngocthi/cp/see.cpp"
using namespace std;

vt id;

struct line {
    int a, b;
    int get(int x) {
        return a * id[x] + b;
    }
};

struct IT {
    int N;
    vector<line> it;

    IT() {
        N = id.size();
        it.assign(4 * N, {0LL, -inf});
    }

    void update(int id, int l, int r, line val) {
        int m = (l + r) / 2;
        bool left = val.get(l) >= it[id].get(l);
        bool mid = val.get(m) >= it[id].get(m);
        if(mid)
            swap(it[id], val);
        if(l == r)
            return;
        if(left != mid)
            update(id * 2, l, m, val);
        else
            update(id * 2 + 1, m + 1, r, val);
    }

    void update(line val) {
        update(1, 0, N - 1, val);
    }

    int query(int id, int l, int r, int x) {
        int res = it[id].get(x);
        int m = (l + r) / 2;
        if(l == r)
            return res;
        if(x < m)
            return max(res, query(id * 2, l, m, x));
        return max(res, query(id * 2 + 1, m + 1, r, x));
    }

    int query(int x) {
        return query(1, 0, N - 1, x);
    }
};

struct hcn {
    int x, y, a;

    bool operator<(hcn &o) const {
        if(x != o.x)
            return x < o.x;
        return a < o.a;
    }
};

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<hcn> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y >> a[i].a, id.push_back(a[i].y);
    sort(a.begin() + 1, a.end());
    _sort(id);
    uni(id);
    int res = 0;
    vt dp(n + 1);
    dp[0] = 0;
    a[0].x = 0;
    IT it;
    it.update({-a[0].x, dp[0]});
    int idx = id.size() - 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = -a[i].a + a[i].y * a[i].x + it.query(idx--);
        res = max(res, dp[i]);
        it.update({-a[i].x, dp[i]});
    }
    cout << res;
}