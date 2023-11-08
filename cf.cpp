#include <bits/stdc++.h>
#define ll long long
#define int long long
#define hi cerr << "HIHIHI\n";
using namespace std;

struct FT {
    int n;
    vector<int> bit;

    void init(int _n) {
        n = _n;
        bit.resize(n + 1);
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
        if(l == 0) {
            return get(r);
        }
        return get(r) - get(l - 1);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> vals;
    map<int,bool> exist;
    for(int &x : a) {
        cin >> x;
        if(exist.find(x) == exist.end()) {
            vals.push_back(x);
            exist[x] = true;
        }
    }
    sort(vals.begin(), vals.end());
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }
    FT fenMin;
    fenMin.init(n + 1);
    vector<int> cnt(vals.size()), rem(n);
    for(int i = n - 1; i >= 0; i--) {
        ++cnt[a[i]];
        fenMin.add(cnt[a[i]], 1);
        rem[i] = cnt[a[i]];
    }
    int ans = 0;
    cnt.assign(n, 0);
    for(int i = 0; i < n - 1; i++) {
        ++cnt[a[i]];
        fenMin.add(rem[i], -1);
        ans += fenMin.get(0, cnt[a[i]] - 1);
    }
    cout << ans;
}
