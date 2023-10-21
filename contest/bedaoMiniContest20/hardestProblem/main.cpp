#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Query {
	int l, r, val;
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<Query> queries;
	for(int i = 0; i < q; i++) {
		int type, l, r;
		cin >> type >> l >> r;
		l--, r--;
		if(type == 1) {
			int val;
			cin >> val;
			queries.push_back({l, r, val});
		} else {
			int ans = 0;
			for(auto[_l, _r, val] : queries) {
				int L = max(_l, l), R = min(_r, r);
				if(L <= R && (R - L + 1) % 2 == 1) {
					ans ^= val;
				} 	
			}
			cout << ans << '\n';
			queries.clear();
		}
	}
}
