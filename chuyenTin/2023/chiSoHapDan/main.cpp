#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int p, q;
    string s;
    cin >> p >> s >> q;
    auto check = [&](int l, int r) -> bool {
        ll res = 0;
        for(int i = l; i <= r; i++) {
            res = res * 10 + s[i] - '0';
            res %= p;
        }
        return res == 0;
    };
    auto sub1 = [&]() -> void {
        int n = s.length();
        vector<pair<int,int>> b;
        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {
                if(check(l, r)) b.push_back({l, r});
            }
        }
        while(q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int ans = 0;
            for(auto x : b) {
                if(x.first >= l && x.second <= r) ans++;
            }
            cout << ans << '\n';
        }
    };
    auto sub2 = [&]() -> void {
        int n = s.length();
        s = ' ' + s;
        vector<int> cnt(n + 1);
        vector<ll> dp(n + 1);
        for(int i = 1; i <= n; i++) {
            int d = s[i] - '0';
            cnt[i] = cnt[i - 1];
            dp[i] = dp[i - 1];
            if(d % 2 == 0) {
                cnt[i]++;
                dp[i] += i;
            }
        }
        while(q--) {
            int l, r;
            cin >> l >> r;
            cout << dp[r] - dp[l - 1] - (l - 1) * (cnt[r] - cnt[l - 1]) << '\n';
        }
    };
    if(max((int)s.length(), q) <= 100) sub1();
    else if(p == 2) sub2();
    return 0;
}