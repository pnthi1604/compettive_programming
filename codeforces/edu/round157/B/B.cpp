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
		n = 2 * n;
		vector<int> a(n);
		for(int &x : a)
			cin >> x;
		sort(a.begin(), a.end());
		vector<int> Ox(a.begin(), a.begin() + n / 2), Oy(a.begin() + n / 2, a.end());
		int res = 0;
		for(int i = 0; i < n / 2 - 1; i++) {
			res += (Ox[i + 1] - Ox[i]) + (Oy[i + 1] - Oy[i]);
		}
		cout << res << '\n';
		for(int i = 0; i < n / 2; i++) {
			cout << Ox[i] << ' ' << Oy[i] << '\n';
		}
	} 
}