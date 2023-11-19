#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[18][10][2][2];
vector<int> num;

void solve(int n) {
	num.clear();
	while(n) {
		num.push_back(n % 10);
		n /= 10;
	}
	reverse(num.begin(), num.end());
	for(int i = 0; i < 18; i++)
		for(int j = 0; j < 10; j++)
			for(int k = 0; k < 2; k++)
				for(int l = 0; l < 2; l++)
					dp[i][j][k][l] = -1;
}

int init = 0;

int dq(int i, int last, int tight, int start) {
	if(i == num.size()) {
		return 1;
	}
	if(dp[i][last][tight][start] != -1) {
		return dp[i][last][tight][start];
	}
	int res = 0;
	if(i == 0) {
		res = init;
	}
	for(int d = 0; d < 10; d++) {
		if(i == 0) {
			if(d == 0)
				res += dq(i + 1, 0, 0, 0);
			else if(d == num[i]) 
				res += dq(i + 1, d, 1, 1);
			else if(d < num[i])
				res += dq(i + 1, d, 0, 1);
		} else {
			if(start != 0 && d != last) {
				if(tight == 0)
					res += dq(i + 1, d, 0, 1);
				else if(d == num[i])
					res += dq(i + 1, d, 1, 1);
				else if(d < num[i])
					res += dq(i + 1, d, 0, 1);
			} else if(start == 0) {
				if(d == 0)
					res += dq(i + 1, d, 0, 0);
				else
					res += dq(i + 1, d, 0, 1);
			}
		}
	}
	return dp[i][last][tight][start] = res;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b;
	cin >> a >> b;
	init = 0;
	if(a - 1 >= 0) {
		solve(a - 1);
		init = -dq(0, 0, 0, 0);
	}
	solve(b);
	cout << dq(0, 0, 0, 0); 
}