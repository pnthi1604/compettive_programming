#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, k;

int cntBoom(int v, vector<string> a) {
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] != 'x')
				continue;
			cnt++;
			for(int t = j; t <= min(j + 2 * v, m - 1); t++) {
				if(a[i][t] == '#')
					break;
				a[i][t] = '.';
			}
		}
	}
	return cnt;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	vector<string> a(n);
	for(auto &x : a)
		cin >> x;
	int l = 0, r = m * n, ans = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		int booms = cntBoom(mid, a);
		if(booms > k) {
			l = mid + 1;
		} else {
			ans = mid;
			r = mid - 1;
		}
	}
	cout << ans;
}