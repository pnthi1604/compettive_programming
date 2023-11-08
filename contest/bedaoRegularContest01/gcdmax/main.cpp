#include <bits/stdc++.h>
#define int long long

using namespace std;

struct ST {
	vector<int> st, a;
	int n;

	void init(vector<int> &arr) {
		a = arr;
		n = a.size();
		st.resize(n * 4);
		build(1, 0, n - 1);
	}

	void build(int id, int l, int r) {
		if(l == r) {
			st[id] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build(id * 2, l, m);
		build(id * 2 + 1, m + 1, r);
		st[id] = gcd(st[id * 2], st[id * 2 + 1]);
	}

	int get(int id, int l, int r, int u, int v) {
		if(l > v || r < u) {
			return 0;
		}
		if(l >= u && r <= v) {
			return st[id];
		}
		int m = (l + r) / 2;
		int get1 = get(id * 2, l, m, u, v);
		int get2 = get(id * 2 + 1, m + 1, r, u, v);
		return gcd(get1, get2);
	}

	int get(int l, int r) {
		return get(1, 0, n - 1, l, r);
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x : a)
		cin >> x;
	ST st;
	st.init(a);
	int ans = st.get(0, n - 1);
	if(a.size() == 1) {
		cout << (int)1e9;
		return 0;
	}
	for(int i = 0; i < n; i++) {
		int g = 0;
		if(i == 0) {
			g = st.get(i + 1, n - 1);
		} else if(i == n - 1) {
			g = st.get(0, i - 1);
		} else {
			g = gcd(st.get(0, i - 1), st.get(i + 1, n - 1));
		}
		ans = max(ans, g);
	}
	cout << ans;
}