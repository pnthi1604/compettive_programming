#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = (int)1e9;
const int N = 5000;
vector<int> c(1, 0);
int dp[N + 1][N + 1][2];
int n;

int dq(int l, int r, int type) {
	if(l == r) {
		return 0;
	}
	if(dp[l][r][type] != 0) {
		return dp[l][r][type];
	}
	int ans = INF;
	if(type == 0) {
		int cur = c[l];
		ans = min(ans, dq(l + 1, r, 0) + 1);
		ans = min(ans, dq(l, r - 1, 0) + int(c[r] != cur));
		ans = min(ans, dq(l + 1, r, 1) + int(c[r] != cur));
		ans = min(ans, dq(l, r - 1, 1) + int(c[r - 1] != cur) + int(c[r] != cur));
	} else {
		int cur = c[r];
		ans = min(ans, dq(l, r - 1, 1) + 1);
		ans = min(ans, dq(l + 1, r, 1) + int(c[l] != cur));
		ans = min(ans, dq(l, r - 1, 0) + int(c[l] != cur));
		ans = min(ans, dq(l + 1, r, 0) + int(c[l + 1] != cur) + int(c[l] != cur));
	}
	return dp[l][r][type] = ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(c.back() != x) {
			c.push_back(x);
		}
	}
	n = c.size() - 1;
	if(n == 1) {
		cout << 0;
		return 0;
	}
	cout << min(dq(1, n, 0), dq(1, n, 1));
	return 0;
}