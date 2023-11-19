#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool check(string &s, int l, int r) {
	for(int k = 1; r - 2 * k >= l; k++) {
		for(int i = r; i - 2 * k >= l; i--) {
			if(s[i] == s[i - k] && s[i] == s[i - 2 * k]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int n = s.length();
	s = '#' + s;
	int cnt = 0;
	for(int i = 1; i <= n - 2; i++) {
		for(int j = i + 2; j <= n; j++) {
			if(check(s, i, j)) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}