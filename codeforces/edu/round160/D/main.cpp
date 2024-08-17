#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'
#define int ll

using namespace std;

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n + 1);
	for(int i = 1; i <= n; i++) cin >> p[i];
	vector<ll> dp(n + 1);
	dp[1] = 1;
	for(int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for(int j = i - 1; j >= 1; j--) 
			if(p[j] < p[i]) {
				dp[i] += dp[j] - 1;
				break;
			}
		dp[i] %= MOD;
	}
	// for(int i = 1; i <= n; i++)
		// cerr << "dp[" << i << "] = " << dp[i] << endl;
	cout << dp[n] % MOD << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}