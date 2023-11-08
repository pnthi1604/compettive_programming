#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int x, y, k;
		cin >> x >> y >> k;
		if(x >= y) {
			cout << x << '\n';
		} else {
			if(k == 0) {
				cout << 2 * y - x << '\n';
				continue;
			}
			int ans = (int)1e9;
			for(int i = x; i <= y; i++) {
				ans = min(ans,  i + max(0LL, (i - x - 1) / k) + 2 * (y - i));
			}
			cout << ans << '\n';
		}
	}
}