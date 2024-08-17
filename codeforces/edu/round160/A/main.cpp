#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

void solve() {
	string s;
	cin >> s;
	auto calc = [&](int l, int r) -> int {
		int res = 1;
		for(int i = l; i <= r; i++)
			res = res * 10 + s[i] - '0';
		return res;
	};
	auto print = [&](int l, int r) -> void {
		for(int i = l; i <= r; i++)
			cout << s[i];
		cout << ' ';
	};
	for(int i = s.length() - 1; i >= 1; i--) 
		if(s[i] != '0' && calc(i, s.length() - 1) > calc(0, i - 1)) {
			print(0, i - 1);
			print(i, s.length() - 1);
			cout << endl;
			return;
		}
	cout << -1 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}