#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    int n = s.length() - 1;
    vector<int> cnt_a(n + 1, 0), cnt_c(n + 1, 0), cnt_v(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cnt_a[i] = cnt_a[i - 1];
        cnt_c[i] = cnt_c[i - 1];
        cnt_v[i] = cnt_v[i - 1];
        if(s[i] == 'A') cnt_a[i]++;
        else if(s[i] == 'C') cnt_c[i]++;
        else cnt_v[i]++;
    }
    auto check = [&](int l, int r) -> bool {
        int sum_a = cnt_a[r] - cnt_a[l - 1];
        int sum_c = cnt_c[r] - cnt_c[l - 1];
        int sum_v = cnt_v[r] - cnt_v[l - 1];
        return min({sum_a, sum_c, sum_v}) >= k;
    };
    int ans = n + 1;
    for(int i = 1; i <= n; i++) {
        int l = 1, r = i, res = -1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(check(m, i)) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if(res == -1) continue;
        // cerr << "i = " << i << endl;
        // cerr << "res = " << res << endl;
        int ka = cnt_a[i] - cnt_a[res - 1];
        int kc = cnt_c[i] - cnt_c[res - 1];
        int kv = cnt_v[i] - cnt_v[res - 1];
        // cerr << "ka = " << ka << endl;
        // cerr << "kc = " << kc << endl;
        // cerr << "kv = " << kv << endl;
        ans = min(ans, ka + kc + kv - 3 * k);
    }
    cout << (ans == n + 1 ? -1 : ans);
    return 0;
}