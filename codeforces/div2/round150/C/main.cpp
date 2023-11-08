#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()

using namespace std;

const int inf = (int)1e18;
string s;
vector<int> getVal(6);
vector<vector<vector<int>>> dp;

int dq(int i, int last, int type) {
	if(i == s.length()) {
		return 0;
	}
	if(dp[i][last][type] != -1) {
		return dp[i][last][type];
	}
	int res = -inf;
	int cur = s[i] - 'A' + 1;
	if(type == 0) {
		for(int c = 1; c < 6; c++) {
			int newLast = max(last, c);
			if(c == cur) {
				if(c >= last)
					res = max(res, dq(i + 1, newLast, 0) + getVal[c]);
				else
					res = max(res, dq(i + 1, newLast, 0) - getVal[c]);
			} else {
				if(c >= last) {
					res = max(res, dq(i + 1, newLast, 1) + getVal[c]);
				} else {
					res = max(res, dq(i + 1, newLast, 1) - getVal[c]);
				}
			}
		}
	} else {
		if(cur >= last)
			res = max(res, dq(i + 1, cur, 1) + getVal[cur]);
		else
			res = max(res, dq(i + 1, last, 1) - getVal[cur]);
	}
	return dp[i][last][type] = res;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	for(char c = 'A'; c <= 'E'; c++) {
		int x = c - 'A' + 1;
		if(x == 1) {
			getVal[x] = 1;
		} else {
			getVal[x] = 10 * getVal[x - 1];
		}
	}
	while(t--) {
		cin >> s;
		reverse(all(s));
		dp.assign(s.length(), vector<vector<int>>(6, vector<int>(2, -1)));
		cout << dq(0, 0, 0) << '\n';
	}
}