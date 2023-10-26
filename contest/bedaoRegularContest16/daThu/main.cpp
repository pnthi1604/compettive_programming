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
		if(n & 1) {
			cout << "Lihwy\n";
		} else {
			cout << "FireGhost\n";
		}
	}
}