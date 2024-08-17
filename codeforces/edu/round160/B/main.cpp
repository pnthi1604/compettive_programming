#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

void solve() {
	string s;
	cin >> s;
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < s.length(); i++) {
		cnt0 += (s[i] == '0');
		cnt1 += (s[i] == '1');
	}
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '0') cnt1--;
		else cnt0--;
		if(cnt0 == -1 || cnt1 == -1) {
			cout << s.length() - i << endl;
			return;
		}
	}
	cout << 0 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}