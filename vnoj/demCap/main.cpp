#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> st;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int cnt = 1;
		while(st.size() && st.back().first <= x) {
			ans += st.back().second;
			if(st.back().first == x)
				cnt += st.back().second;
			st.pop_back();
		}
		if(st.size())
			ans += 1;
		st.push_back({x, cnt});
	}
	cout << ans;
}