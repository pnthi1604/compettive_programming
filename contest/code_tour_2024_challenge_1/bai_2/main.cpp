#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	int x = n / k + (n % k != 0);
	cout << 1ll * x * (x + 1) / 2;
	return 0;
}