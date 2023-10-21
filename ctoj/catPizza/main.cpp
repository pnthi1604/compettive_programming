#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> st(1, 0);
	for(int i = 0; i < n; i++) {
		int deg;
		cin >> deg;
		for(int &x : st)
			x = (x + deg) % 360;
		st.push_back(360);
	}
	sort(st.begin(), st.end());
	int res = st[0];
	for(int i = 1; i <= n; i++) {
		res = max(res, st[i] - st[i - 1]);
	}
	cout << res;
}
