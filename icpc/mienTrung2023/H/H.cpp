#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int &x : a)
		cin >> x;
	int ans = -1;
	while(m--) {
		int x, y, z;
		cin >> x >> y >> z;
		int cnt = 0, res = n;
		int l = 0, r = 0;
		for(int i = 1; i < n; i++) {
			cerr << "ai = " << a[i] << '\n';
			cerr << "l = " << l << "; r = " << r << '\n';
			while(l < i && a[l] + y < a[i]) {
				l++;
			}
			if(l == i)
				l--;
			while(r < i && a[r] + x < a[i]) {
				r++;
			}
			if(r == i)
				r--;
			cerr << "l = " << l << "; r = " << r << '\n';
			if(a[l] >= a[i] - y && a[l] <= a[i] - x && a[r] >= a[i] - y && a[r] <= a[i] - x && a[r] >= a[l]) {
				cnt += (r - l + 1);
				cerr << "a[i] = " << a[i] << "; cnt = " << cnt << '\n';
				if(cnt >= z) {
					res = i;
					break;
				}
			}
		}
		ans = max(ans, res);
	}
	if(ans == n) {
		cout << -1;
	} else {
		cout << a[ans];
	}
}