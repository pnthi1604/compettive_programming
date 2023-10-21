#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1, 0);
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			for(int i = l; i <= r; i++)
				a[i] ^= x;
		} else {
			int l, r;
			cin >> l >> r;
			int res = 0;
			for(int i = l; i <= r; i++) 
				res ^= a[i];
			cout << res << '\n';
			for(int i = 1; i <= n; i++)
				a[i] = 0;
		}
	}
}