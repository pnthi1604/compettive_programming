#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll l, r;
    cin >> l >> r;
    ll p = 1;
    ll ans = 0;
    auto calc = [&](ll x, ll k) -> ll {
        return x / k;
    };
    while(p <= r / 2) {
        p *= 2;
        ans += calc(r, p) - calc(l - 1, p);
    }
    cout << ans;
    return 0;
}