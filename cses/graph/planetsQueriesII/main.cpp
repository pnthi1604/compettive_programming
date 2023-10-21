#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = (int)2e5, maxh = 31;
vector<vector<int>> child(maxh, vector<int>(maxn, -1));
int n, q;

int findKChild(int u, int k) {
	for(int h = maxh - 1; h >= 0; h--) {
		if(k - (1 << h) >= 0) {
			u = child[h][u];
			k -= (1 << h);
		}
	}
	return u;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		int v;
		cin >> v;
		v--;
		child[0][i] = v;
	}
	for(int h = 1; h < maxh; h++) {
		for(int i = 0; i < n; i++) {
			child[h][i] = child[h - 1][child[h - 1][i]];
		}
	}
	for(int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
	}
}