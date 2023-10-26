#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> cnt(26, 0);
		string s;
		cin >> s;
		for(char x : s) {
			int c = x - 'a';
			cnt[c]++;
		}
		int cntDel = 0;
		for(int i = 0; i < 26; i++) {
			if(cnt[i] & 1) {
				cntDel++;
			}
		}
		if(k < cntDel - 1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}