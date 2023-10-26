#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int ans = 0, cur = 1;
		for(int i = 0; i < 4; i++) {
			int digit = s[i] - '0';
			if(digit == 0)
				digit = 10;
			while(cur < digit) {
				cur++;
				ans++;
			}
			while(cur > digit) {
				cur--;
				ans++;
			}
			ans++;
		}
		cout << ans << '\n';
	}
}