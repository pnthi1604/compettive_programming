//https://codeforces.com/contest/86/problem/D
#include <bits/stdc++.h>
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
#define int long long
using namespace std;
int B;
vt cnt(1 << 20), a;
int res;
struct qr {
    int l, r, id;
    bool operator<(qr o) const {
        if(l / B != o.l / B)
            return l / B < o.l / B;
        return r < o.r;
    }
};

void add(int i) {
    int val = a[i];
    res += (2 * cnt[val] + 1) * val;
    cnt[val]++;
}

void del(int i) {
    int val = a[i];
    res += (-2 * cnt[val] + 1) * val;
    cnt[val]--;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    B = (int)sqrt(n);
    vt ans(m);
    a.resize(n);
    for(int &x : a)
        cin >> x;
    vector<qr> qrs;
    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        qrs.push_back({l - 1, r - 1, i});
    }
    _sort(qrs);
    int cur_l = 0, cur_r = -1;
    for(qr q : qrs) {
        while(cur_l > q.l)
            add(--cur_l);
        while(cur_r < q.r)
            add(++cur_r);
        while(cur_l < q.l)
            del(cur_l++);
        while(cur_r > q.r)
            del(cur_r--);
        ans[q.id] = res;
    }
    for(int x : ans)
        cout << x << '\n';
}
