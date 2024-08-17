#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = 2001;
const int INF = (int)1e9;
int dp[N][N];
int a[N], b[N];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dp[i][j] = INF;
	auto dq = [&](auto dq, int l, int r) -> int {
		if(l > r) return 1;
		if(l == r) return a[l] * b[r];
		// if(l + 1 == r) return a[l] * b[r] + a[l + 1] * b[r - 1];
		if(dp[l][r] != INF) return dp[l][r];
		return dp[l][r] = dq(dq, l + 1, r - 1) + a[l] * b[r] + a[r] * b[l];
	};
	int ans = -INF;
	for(int i = 1; i <= n; i++) 
		for(int j = i; j <= n; j++)
			ans = max(ans, dq(dq, i, j));
	cout << ans;
	//gọi f[i][j] là giá trị của hai dãy từ i đến j, lấy max(f) là kết quả
	return 0;
}