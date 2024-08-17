#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	ll n, P, l, t;
	cin >> n >> P >> l >> t;
	ll k = (n - 1) / 7 + 1;
	auto ft = [&](ll a, ll b) -> ll {
		return a % b == 0 ? a / b : a / b + 1;
	};
	ll needDay = 0;
	if(t * k + l * ft(k, 2) < P) {
		needDay = ft(P - (t * k + l * ft(k, 2)), l) + ft(k, 2);
	} else {
		ll lk = 0, rk = k, res = rk;
		while(lk <= rk) {
			ll mid = (lk + rk) / 2;
			if(t * mid + l * ft(mid, 2) >= P) {
				res = mid;
				rk = mid - 1;
			} else {
				lk = mid + 1;
			}
		}
		needDay = ft(res, 2);
	}
	cout << n - needDay << '\n';
}
	

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}