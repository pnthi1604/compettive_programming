#include <bits/stdc++.h>
#define int long long

using namespace std;

const int inf = (int)1e18;
int n;
vector<int> a;

vector<vector<vector<int>>> dp;

int dq(int i, int j, int k) {
	if(i == n)
		return 0;
	if(dp[i][j][k] != -1)
		return dp[i][j][k];
	int res = -inf;
	if(j == 0) 
		res = max({dq(i + 1, 0, 0) + a[i], dq(i + 1, 1, 1) - a[i], res});
	else if(j == 1) {
		if(k == 1) {
			res = max({dq(i + 1, 1, 1) - a[i], dq(i + 1, 1, 0) + a[i], res});
		} else if(k == 0) {
			res = max({dq(i + 1, 1, 0) + a[i], dq(i + 1, 2, 1) - a[i], res});
		}
	} else {
		if(k == 2) {
			res = max({dq(i + 1, 2, 2) + a[i], dq(i + 1, 2, 0) + a[i]});
		} else if(k == 1) {
			res = max({dq(i + 1, 2, 0) + a[i], dq(i + 1, 2, 1) - a[i], res});
		} else if(k == 0) {
			res = max(res, dq(i + 1, 2, 0) + a[i]);
		}
	}
	return dp[i][j][k] = res;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n);
	for(int &x : a)
		cin >> x;
	if(n <= 0) {
		cout << 0;
		return 0;
	}
	if(n == 1) {
		cout << a[0];
		return 0;
	}
	dp.assign(n, vector<vector<int>>(3, vector<int>(3, -1)));
	cout << dq(0, 0, 0);
}