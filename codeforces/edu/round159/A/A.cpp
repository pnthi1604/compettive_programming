#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool ok = false;
	int cnt_0 = 0, cnt_1 = 0;
	for(char c : s) {
		cnt_0 += c == '0';
		cnt_1 += c == '1';
	}
	for(int i = 0; i < n - 1; i++) {
		string ss = "";
		ss += s[i];
		ss += s[i + 1];
		if(ss == "01" || ss == "10") {
			ok = true;
			break;
		}
	}
	cout << ((ok == true || cnt_0 > cnt_1) ? "YES\n" : "NO\n");
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}