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
		int a = -1, b = -1, c = -1;
		if(n - 3 > 0 && (n - 3) % 3 && n - 3 != 1 && n - 3 != 2) {
			a = 1, b = 2, c = n - 3;
		} else if(n - 5 > 0 && (n - 5) % 3 && n - 5 != 1 && n - 5 != 4) {
			a = 1, b = 4, c = n - 5;
		} else if(n - 7 > 0 && (n - 7) % 3 && n - 7 != 2 && n - 7 != 5) {
			a = 2, b = 5, c = n - 7;
		}
		if(a == -1) {
			cout << "NO\n";
		} else {
			cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
		}
	}
}