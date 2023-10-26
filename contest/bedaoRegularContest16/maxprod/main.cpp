#include <bits/stdc++.h>
#define int long long

using namespace std;

const int inf = (int)1e18;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	int sum = 0;
	vector<int> a(n), b(n);
	for(int &x : a)
		cin >> x;
	for(int &x : b)
		cin >> x;
	for(int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] < b[i])
			swap(a[i], b[i]);
		int x = a[i], y = b[i];
		int l = 0, r = k, res = abs(x + k - y), mid = k;
		while(l <= r) {
			int m = (l + r) / 2;
			if(abs(x + m - (y + k - m)) <= res) {
				res = abs(x + m - (y + k - m));
				mid = m;
			}
			if(x + m - (y + k - m) >= 0) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		ans = max(ans, sum - x * y + (x + mid) * (y + k - mid));
	}
	cout << ans;
}