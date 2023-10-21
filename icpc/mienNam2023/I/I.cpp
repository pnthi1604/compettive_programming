#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = (int)1e9 + 7;

int bpow(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return res;
}

signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x : a)
		cin >> x;
	if(n <= 2) {
		cout << 0;
		return 0;
	}
	sort(a.begin(), a.end());
	vector<vector<int>> dp(n, vector<int>(5001, 0));
	dp[0][a[0]] = 1;
	dp[0][0] = 1;
	for(int i = 1; i < n; i++) {
		for(int w = 0; w <= 5000; w++) {
			dp[i][w] = dp[i - 1][w];
			if(w - a[i] >= 0)
				dp[i][w] += dp[i - 1][w - a[i]];
		}
	}
	int res = 0;
	for(int i = 2; i < n; i++) {
		res += bpow(2, i) % mod;
		for(int w = 0; w <= a[i]; w++) {
			res = (res - dp[i - 1][w] + mod) % mod;
		}
		res %= mod;
	}
	cout << res;
}