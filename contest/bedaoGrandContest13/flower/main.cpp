#include <bits/stdc++.h>
#define int long long

using namespace std;

struct cmp {
	bool operator()(const int &a, const int &b) const {
		return a > b;
	}
};

void checkSet(multiset<int, cmp> a) {
	cerr << "check set\n";
	for(int x : a) {
		cerr << x << ' ';
	}
	cerr << "\nend check set\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for(int i1 = 0; i1 < n; i1++) {
		for(int i2 = i1; i2 < n; i2++) {
		}
	}
	cout << ans;
}