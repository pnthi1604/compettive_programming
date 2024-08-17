#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = (int)3e5;
int n, q;
int a[N];
vector<pair<int,int>> qs[N];
int ans[N];
int vis_id[N];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	struct FT {
		vector<int> bit;
		int n;
		void init(int _n) {
			n = _n;
			bit.resize(n + 1);
		}
		void update(int x, int val) {
			for(int i = x + 1; i <= n; i += i & -i) {
				bit[i] ^= val;
			}
		}
		int get(int x) {
			int res = 0;
			for(int i = x + 1; i >= 1; i -= i & -i) 
				res ^= bit[i];
			return res;
		}
		int get(int l, int r) {
			return get(r) ^ get(l - 1);
		}
	};
	FT ft;
	ft.init(n);
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		qs[r].push_back({l, i});
	}
	vector<int> vals;
	for(int x : a) vals.push_back(x);
	sort(vals.begin(), vals.end());
	for(int i = 0; i < vals.size(); i++) vis_id[i] = -1;
	for(int i = 0; i < n; i++) {
		int x = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
		if(vis_id[x] != -1) {
			ft.update(vis_id[x], a[i]);
		}
		vis_id[x] = i;
		ft.update(i, a[i]);
		for(auto[l, id] : qs[i]) {
			ans[id] = ft.get(l, i);
		}
	}
	for(int i = 0; i < q; i++) cout << ans[i] << ' ';
	return 0;
}
