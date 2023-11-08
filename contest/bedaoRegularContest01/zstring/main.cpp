#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	string s = "";
	for(char c = 'a'; c <= 'z'; c++)
		s += c;
	while(q--) {
		int n;
		cin >> n;
		if(n == 1) {
			int len;
			cin >> len;
			string res = s.substr(0, len - 1);
			reverse(res.begin(), res.end());
			res = "z" + res;
			cout << res << '\n';
		} else if(n == 2) {
			int len1, len2;
			cin >> len1 >> len2;
			if(len1 > 1) {
				if(len2 == 26) {
					cout << -1;
				} else {
					string res2 = s.substr(1, len2);
					string res1 = s.substr(0, len1 - 1);
					reverse(res1.begin(), res1.end());
					res1 = "z" + res1 + res2;
					cout << res1 << '\n';
				}
			} else {
				cout << "-1\n";
			}
		} else {
			cout << "tuikhumbiet\n";
		}
	}
}