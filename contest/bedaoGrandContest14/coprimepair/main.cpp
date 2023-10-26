#include <bits/stdc++.h>
#define int long long
#define hi cerr << "HIHIHI\n";

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	n++;
	vector<int> a(n);
	for(int &x : a)
		cin >> x;
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(gcd(a[i], a[j]) == 1) {
				cout << a[i] << ' ' << a[j];
				return 0;
			}
		}
	}
	cout << -1;
}
