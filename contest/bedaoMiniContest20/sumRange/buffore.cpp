#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int &x : a)
		cin >> x;
	for(int &x : b)
		cin >> x;
	for(int i = 1; i < n; i++) {
		a[i] += a[i - 1];
		b[i] += b[i - 1];
	}
	int ans = 0;
	for(int x = 0; x < n; x++) {
		for(int y = x; y < n; y++) {
			for(int c = 0; c < n; c++) {
				for(int d = c; d < n; d++) {
					int res = 0;
					for(int i = x; i <= y; i++) {
						for(int j = c; j <= d; j++) {
							if(i <= j) {
								if(i == 0)
									res += a[j];
								else
									res += a[j] - a[i - 1];
							} else {
								if(j == 0)
									res += b[i];
								else
									res += b[i] - b[j - 1];
							}
						}
					}
					ans = max(ans, res);
				}
			}
		}
	}
	cout << ans;
}