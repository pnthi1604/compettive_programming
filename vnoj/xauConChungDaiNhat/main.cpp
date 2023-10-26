#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string a, b;
	cin >> a >> b;
	int na = a.size(), nb = b.size();
	vector<int> dp(nb + 1, 0);
	dp[0] = 0;
	for(int i = 1; i <= na; i++) {
		vector<int> newDp(nb + 1, 0);
		for(int j = 1; j <= nb; j++) {
			newDp[j] = max(dp[j], newDp[j - 1]);
			if(a[i - 1] == b[j - 1]) {
				newDp[j] = max(newDp[j], dp[j - 1] + 1);
			}
		}
		for(int j = 1; j <= nb; j++) {
			dp[j] = newDp[j];
		}
	}
	cout << dp[nb];
}