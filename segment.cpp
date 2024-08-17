#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

struct SegmentTree{
	vector<int> st;
	vector<pair<int, int>> lazy;
	int n;
	SegmentTree(vector<int>& arr) {
		n = (int) arr.size();
		st.resize(4 * n + 33);
		lazy.resize(4 * n + 33, {1, 0});
		build(1, 0, n - 1, arr);
	}
	void build(int id, int l, int r, vector<int>& arr) {
		if (l == r) {
			st[id] = arr[l];
			return ;
		}
		int m = (l + r) / 2;
		build(id * 2, l, m, arr);
		build(id * 2 + 1, m + 1, r, arr);
		st[id] = (st[id * 2] + st[id * 2 + 1]) % MOD;
	}
	void calc(pair<int, int>& child, pair<int, int>& par) {
		// child.first = (1ll * child.first * par.first) % MOD;
		// child.second = (1ll * child.second * par.first % MOD + par.second) % MOD;
		child = par;
	}
	int f(int id, int l, int r, pair<int, int>& ff) {
		return (1ll * ff.first * st[id] % MOD + 1ll * (r - l + 1) * ff.second % MOD) % MOD;
	}
	void pushdown(int id, int l, int r) {
		if (l != r) {
			int m = (l + r) / 2;
			st[id * 2] = f(id * 2, l, m, lazy[id]);
			st[id * 2 + 1] = f(id * 2 + 1, m + 1, r, lazy[id]);
			calc(lazy[id * 2], lazy[id]);
			calc(lazy[id * 2 + 1], lazy[id]);
		} 
		lazy[id] = {1, 0};
	}
	void update(int id, int l, int r, int u, int v, pair<int, int> ff) {
		pushdown(id, l, r);
		if (u > r || v < l) return ;
		if (u <= l && r <= v) {
			st[id] = f(id, l, r, ff);
			calc(lazy[id], ff);
			return ;
		}
		int mid = (l + r) / 2;
		update(id * 2, l, mid, u, v, ff);
		update(id * 2 + 1, mid + 1, r, u, v, ff);
		st[id] = (st[id * 2] + st[id * 2 + 1]) % MOD;
	}
	int get(int id, int l, int r, int u, int v) {
		pushdown(id, l, r);
		if (u > r || v < l) 
			return 0;
		else if (u <= l && r <= v) 
			return st[id];
		int m = (l + r) / 2;
		return (get(id * 2, l, m, u, v) + get(id * 2, m + 1, r, u, v)) % MOD;
	}
	void update(int l, int r, pair<int, int> ff) {
		update(1, 0, n - 1, l, r, ff);
	}
	int get(int l, int r) {
		return get(1, 0, n - 1, l, r);
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	SegmentTree st(a);
	while (q--) {
		int type; cin >> type;
		if (type == 0) {
			int l, r, b, c; cin >> l >> r >> b >> c;
			r--;
			st.update(l, r, {b, c});
		} else {
			int l, r; cin >> l >> r;
			r--;
			cout << st.get(l, r) << '\n';
		}
	}
}