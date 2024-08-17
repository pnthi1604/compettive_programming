#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = (int)1e5;
int a[N];

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int &x : a) cin >> x;
	struct ST {
		vector<int> t;
		int n;
		void init(int _n) {
			n = _n;
			t.resize(4 * n);
			build(1, 0, n - 1);
		}
		void build(int id, int l, int r) {
			if(l == r) {
				t[id] = a[l];
				return;
			}
			int m = (l + r) / 2;
			build(id * 2, l, m);
			build(id * 2 + 1, m + 1, r);
			combine(id);
		}
		int combine(int a, int b) {
			return __gcd(a, b);
		}
		void combine(int id) {
			t[id] = combine(t[id * 2], t[id * 2 + 1]);
		}
		int get(int id, int l, int r, int u, int v) {
			if(l > v || r < u) return 0;
			if(l >= u && r <= v) return t[id];
			int m = (l + r) / 2;
			int get1 = get(id * 2, l, m, u, v);
			int get2 = get(id * 2 + 1, m + 1, r, u, v);
			return combine(get1, get2);
		}
		int get(int l, int r) {
			return get(1, 0, n - 1, l, r);
		}
	};
	ST st;
	st.init(n);
	int ans = 1;
	for(int i = 0; i < n; i++) {
		if(i == 0 && i + 1 <= n - 1)
			ans = max(ans, st.get(i + 1, n - 1));
		else if(i == n - 1 && i - 1 >= 0)
			ans = max(ans, st.get(0, i - 1));
		else
			ans = max(ans, st.combine(st.get(0, i - 1), st.get(i + 1, n - 1)));
	}
	cout << ans;
	return 0;
}