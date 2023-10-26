#include <bits/stdc++.h>
#define int long long

using namespace std;

const int inf = (int)1e18;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int &x : a)
			cin >> x;
		vector<vector<int>> dp(n + 1, vector<int>(k, inf));
		dp[0][1] = 0;
		for(int i = 1; i <= n; i++) {
			for(int r = 0; r < k; r++) {
				for(int j = 0; j < k; j++) {
					dp[i][(a[i - 1] + r) * j % k] = min(dp[i][(a[i - 1] + r) * j % k], dp[i - 1][j] + r);
				}
			}
		}
		cout << dp[n][0] << '\n';
	}
}