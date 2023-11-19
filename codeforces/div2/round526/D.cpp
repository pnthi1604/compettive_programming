#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int n = s.length();
	s = '#' + s;
	vector<ll> dp(n + 1, 0), index(n + 1);
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + index[i - 1];
		index[i] = index[i - 1];
		for(int k = 1; i - 2 * k > index[i]; k++) {
			if(s[i] == s[i - k] && s[i] == s[i - 2 * k]) {
				index[i] = i - 2 * k;
				break;
			}
		}
		dp[i] += index[i] - index[i - 1];
	} 		
	cout << dp[n];
	return 0;
}