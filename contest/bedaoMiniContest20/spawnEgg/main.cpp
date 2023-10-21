#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int t, k, n;
		cin >> t >> k >> n;
		if(n < t) {
			cout << 0 << '\n';
		} else {
			cout << 1 + (n - t) / k << '\n';
		}
	}
}