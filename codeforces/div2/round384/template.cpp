#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for(int i = 0; i < n; i++) {
			cerr << "a[" << i << "] = " << a[i] << endl;
		}
		int ans = 0;
		for(int x : a) ans += x;
	}
}