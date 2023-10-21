#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> solve(vector<int> &a) {
	int n = a.size();
	vector<int> lis, liq(n, 1);
	for(int i = 0; i < n; i++) {
		int id = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
		if(id >= 0 && id < lis.size()) {
			liq[i] = id + 1;
			lis[id] = a[i];
		} else {
			lis.push_back(a[i]);
			liq[i] = lis.size();
		}
	}
	return liq;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x : a)
		cin >> x;
	vector<int> liqa, liqb;
	liqa = solve(a);
	reverse(a.begin(), a.end());
	liqb = solve(a);
	int res = 1;
	for(int i = 0; i < liqa.size(); i++) {
		res = max(res, min(liqa[i], liqb[liqa.size() - i - 1]));
	}
	cout << 2 * res - 1;
}