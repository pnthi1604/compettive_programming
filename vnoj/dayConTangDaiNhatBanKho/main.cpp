#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x : a)
		cin >> x;
	vector<int> lis;
	for(int i = 0; i < n; i++) {
		int id = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
		if(id >= 0 && id < lis.size()) {
			lis[id] = a[i];
		} else {
			lis.push_back(a[i]);
		}
	}
	cout << lis.size();
}