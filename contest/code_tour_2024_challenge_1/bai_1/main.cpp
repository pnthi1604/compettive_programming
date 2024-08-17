#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k;
	cin >> k;
	vector<int> a(k);
	for(int &x: a) cin >> x;
	ll r;
	cin >> r;
	int res = 0;
	for(ll i = 0; i <= (int)1e6; i++) {
		if (i * i * i == r) {
			res = i;
			break;
		}
	}
	cout << res;
	return 0;
}