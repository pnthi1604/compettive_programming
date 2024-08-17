#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = (int)1e5;
int a[N];

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	struct FT {
		vector<int> bit;
		int n;
		void init(int _n) {
			n = _n;
			bit.resize(n + 1);
			for(int i = 0; i < n; i++)
				add(i, a[i]);
		}
		void add(int x, int val) {
			for(int i = x + 1; i <= n; i += i & -i)
				bit[i] = __gcd(bit[i], val);
		}
		int get(int x) {
			int res = 0;
			for(int i = x + 1; i >= 1; i -= i & -i)
				res = __gcd(res, bit[i]);
			return res;
		}
	};
	int ans = 0;
	FT ft;
	ft.init(n);
	for(int i = 0; i < n; i++) {
		ft.add(i, 0);
	return 0;
}