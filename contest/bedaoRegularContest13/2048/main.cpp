#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

const int MOD = (int)1e9 + 9;
const int N = (int)1e5;
const int m = 2048;
map<int,int> dp[N + 1];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	s = ' ' + s;
	vector<pair<ll,int>> a(1, {0, 0});
	int i = 1;
	while(i < s.length()) {
		if(s[i] == '?') {
			a.push_back({-1, -1});
			i++;
			continue;
		}
		int j;
		ll r = s[i] - '0';
		for(j = i + 1; j < s.length(); j++)
			if(s[j] == '?') {
				break;
			} else r = (r * 10 + (s[j] - '0')) % m;
		j--;
		a.push_back({r, j - i + 1});
		i = j + 1;
	}
	auto bp = [&](int p) -> ll {
		ll res = 1;
		ll x = 10;
		while(p) {
			if(p & 1)
				res *= x, res %= m;
			x *= x;
			x %= m;
			p >>= 1;
		}
		return res % m;
	};
	dp[0][0] = 1;
	// for(auto[r, p] : a) {
	// 	cerr << r << ' ' << p << endl;
	// }
	// cerr << endl;
	set<int> se;
	se.insert(0);
	for(int i = 1; i < a.size(); i++) {
		auto[r, p] = a[i];
		if(r == -1) {
			vector<int> adds;
			for(int d = 0; d <= 9; d++) 
				for(int j : se) {
					dp[i][(j * 10 + d) % m] += dp[i - 1][j];
					dp[i][(j * 10 + d) % m] %= MOD;
					adds.push_back((j * 10 + d) % m);
				}
			for(int x : adds)
				se.insert(x);
		} else {
			vector<int> adds;
			for(int j : se) {
				dp[i][(j * bp(p) % m + r) % m] += dp[i - 1][j];
				dp[i][(j * bp(p) % m + r) % m] %= MOD;
				adds.push_back((j * bp(p) % m + r) % m);
			}
			for(int x : adds)
				se.insert(x);
		}
	}
	// cerr << dp[1][2] << endl;
	cout << dp[a.size() - 1][0] % MOD;
	return 0;
}