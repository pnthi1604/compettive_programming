#include <bits/stdc++.h>
#define int long long

using namespace std;

int dp[18][2][10][2];
vector<int> num;

void solve(int n) {
	num.clear();
	while(n) {
		num.push_back(n % 10);
		n /= 10;
	}
	reverse(num.begin(), num.end());
	for(int i = 0; i < 18; i++)
		for(int j = 0; j < 2; j++)
			for(int k = 0; k < 10; k++)
				for(int l = 0; l < 2; l++)
					dp[i][j][k][l] = -1;
}

int dq(int i, int tight, int last, int start) {
	if(i == num.size())
		return 1;
	if(dp[i][tight][last][start] != -1)
		return dp[i][tight][last][start];
	int res = 0;
	if(start == 0)
		res = dq(i + 1, tight, last, start);
	for(int digit = 0; digit < 10; digit++) {
		if(digit == last)
			continue;
		if(tight == 0 || (start == 0 && i != 0)) {
			res += dq(i + 1, 0, digit, 1);
		} else {
			if(digit > num[i])
				continue;
			if(digit == num[i])
				res += dq(i + 1, 1, digit, 1);
			else {
				res += dq(i + 1, 0, digit, 1);
			}
		}
	}
	return dp[i][tight][last][start] = res;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b;
	cin >> a >> b;
	solve(b);
	int resb = dq(0, 1, 0, 0);
	int resa = 0;
	if(a != 0) {
		solve(a - 1);
		resa = dq(0, 1, 0, 0);
	}
	cout << resb - resa;
}