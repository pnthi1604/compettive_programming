#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<ll> s(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + a[i];
        }
        ll ans = 0;
        for(int k = 1; k < n; k++) {
            if(n % k) {
                continue;
            }
            int kk = k;
            ll mx = 0, mi = (ll)1e18;
            while(kk <= n) {
                ll sum = s[kk] - s[kk - k];
                mx = max(mx, sum);
                mi = min(mi, sum);
                kk += k;
            }
            ans = max(ans, mx - mi);
        }
        cout << ans << '\n';
    }
    return 0;
}