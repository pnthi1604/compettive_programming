#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; 
	cin >> n;
	vector<int> a(n);
	for(int &x : a) cin >> x;
	auto ok = [&](int n) -> bool {
		for(int i = 2; i * i <= n; i++) 
			if(n % i == 0) return false;
		return n > 1;
	};
	ll ans = 1;
	vector<int> prime;
	for(int i = 2; i < 50; i++)
		if(ok(i)) prime.push_back(i), ans *= i;
	auto check = [&](int res) -> bool {
		for(int i = 0; i < n; i++) 
			if(__gcd(a[i], res) <= 1) return false;
		return true;
	};
	for(int mask = 1; mask < (1 << 15); mask++) {
		ll res = 1;
		for(int j = 0; j < 15; j++) {
			if(mask & (1 << j)) {
				res *= prime[j];
			}
		}
		if(check(res))
			ans = min(ans, res);
	}
	cout << ans;
	return 0;
}