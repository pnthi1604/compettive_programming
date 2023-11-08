#include <bits/stdc++.h>
#define int long long
#define hi cerr << "HIHIHI\n";

using namespace std;

map<int,bool> m[1001];

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for(int j = 0; j < x; j++) {
			int val;
			cin >> val;
			m[i][val] = true;
		}
	}
	while(q--) {
		int val;
		cin >> val;
		int l = 0, r = 0;
		int ans = 0;
		while(l < n && r < n) {
			while(r < n && m[r][val] == false)
				r++;
			l = r;
			while(r < n && m[r][val] == true) {
				r++;
			}
			ans = max(ans, r - l);
		}
		cout << ans << '\n';
	}
};