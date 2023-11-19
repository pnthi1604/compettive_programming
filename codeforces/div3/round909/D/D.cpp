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
        map<int,ll> cnt;
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        for(auto[x, _cnt] : cnt) {
            if(x == 1 || x == 2) {
                continue;
            }
            ans += _cnt * (_cnt - 1) / 2;
        }
        ans += (cnt[1] + cnt[2]) * (cnt[1] + cnt[2] - 1) / 2;
        cout << ans << '\n';
    }
    return 0;
}