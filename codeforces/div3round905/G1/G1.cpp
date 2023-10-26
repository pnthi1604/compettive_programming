#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(n);
		a[0] = 1;
		for(int i = 1; i < n; i++)
			cin >> a[i];
		for(int &x : b)
			cin >> x;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int ia = n - 1, ib = n - 1;
		int ans = 0;
		while(ia >= 0 && ib >= 0) {
			if(a[ia] < b[ib]) {
				ia--, ib--;
			} else {
				ia--;
				ans++;
			}
		}
		cout << ans << '\n';
	}
}