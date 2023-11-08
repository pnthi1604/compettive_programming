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

int dq(int i, int last, int tight, int start) {
	if(i == num.size()) {
		return 1;
	}
	if(dp[i][last][tight][start] != -1) {
		return dp[i][start][tight][start];
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}