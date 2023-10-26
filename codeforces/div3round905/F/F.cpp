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
		vector<bool> exitsLeft(n, false);
		map<int,bool> m;
		for(int i = n - 1; i >= 0; i--) {
			if(m.find(a[i]) != m.end()) {
				exitsLeft[i] = true;
			} else {
				m[a[i]] = true;
			}
		}
		int cnt = 0, ans = 0;
		m.clear();
		for(int i = 0; i < n; i++) {
			if(m.find(a[i]) == m.end()) {
				cnt++;
			}
			m[a[i]] = true;
			if(exitsLeft[i] == false) {
				ans += cnt;
			}
		}
		cout << ans << '\n';
	}
}