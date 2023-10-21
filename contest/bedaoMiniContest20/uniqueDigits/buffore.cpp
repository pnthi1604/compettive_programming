#include <bits/stdc++.h>
#define int unsigned long long

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
		int ans = 0;
		for(int i = 0; i < (1 << n); i++) {
			vector<int> cnt(10, 0);
			int res = 0;
			for(int j = 0; j < n; j++) {
				if(i & (1 << j)) {
					int x = a[j];
					while(x) {
						cnt[x % 10]++;
						x /= 10;
					}
					res += a[j];
				}
			}
			for(int i = 0; i < 10; i++) {
				if(cnt[i] > 1) {
					res = 0;
					break;
				}
			}
			ans = max(ans, res);
		}
		cout << ans << '\n';
	}
}