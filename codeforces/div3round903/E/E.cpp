#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int &x : a)
			cin >> x;
		vector<int> dp(n + 1);
		for(int i = n - 1; i >= 0; i--) {
			dp[i] = dp[i + 1] + 1;
			if(i + 1 + a[i] <= n)
				dp[i] = min(dp[i], dp[i + 1 + a[i]]);
		}
		cout << dp[0] << '\n';
	}
}