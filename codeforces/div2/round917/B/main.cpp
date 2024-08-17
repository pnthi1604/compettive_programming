#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		ll ans = 0;
		set<char> se;
		for(char x : s) {
			se.insert(x);
			ans += se.size();
		}
		cout << ans << endl;
	}
	return 0;
}