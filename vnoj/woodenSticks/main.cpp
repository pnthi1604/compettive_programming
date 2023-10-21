#include <bits/stdc++.h>
#define int long long
using namespace std;

int calLis(vector<int> &a) {
	vector<int> lis;
	for(int i = 0; i < a.size(); i++) {
		int id = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
		if(id >= 0 && id < lis.size()) {
			lis[id] = a[i];
		} else {
			lis.push_back(a[i]);
		}
	}
	return lis.size();
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<pair<int,int>> a;
		for(int i = 0; i < n; i++) {
			int l, w;
			cin >> l >> w;
			a.push_back({l, w});
		}
		sort(a.begin(), a.end(), greater<pair<int,int>>());
		vector<int> b;
		for(int i = 0; i < n; i++)
			b.push_back(a[i].second);
		cout << calLis(b) << '\n';
	}
}