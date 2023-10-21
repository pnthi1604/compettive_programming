#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> dp(1 << n), lastW(1 << n);
	dp[0] = 1;
	lastW[0] = 0;
	for(int mark = 1; mark < (1 << n); mark++) {
		dp[mark] = n;
		lastW[mark] = 0;
		for(int i = 0; i < n; i++) {
			if(mark & (1 << i)) {
				int newDp = dp[mark ^ (1 << i)];
				int newLastW = lastW[mark ^ (1 << i)];
				if(newLastW + a[i] <= x) {
					newLastW += a[i];
				} else {
					newDp++;
					newLastW = a[i];
				}
				if(newDp < dp[mark]) {
					dp[mark] = newDp;
					lastW[mark] = newLastW;
				} else if(newDp == dp[mark] && newLastW < lastW[mark]) {
					lastW[mark] = newLastW;
				}
			}
		}
	}
	cout << dp[(1 << n) - 1];
}