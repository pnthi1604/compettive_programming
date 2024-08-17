#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int i;
	i = 0;
	ll ans = 0;
	auto calc = [&](int n) -> ll {
		return 1ll * n * (n - 1) / 2;
	};
	while(i < n) {
		int j;
		for(j = i + 1; j < n; j++)
			if(s[j] != s[j - 1]) break;
		j--;
		ans += calc(j - i + 1);
		i = j + 1;
	}
	cout << ans;	

	return 0;
}