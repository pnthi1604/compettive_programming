#include <bits/stdc++.h>
#define int long long

using namespace std;

int cnt[6][46];

void solve(string s) {
	int sum = 0;
	for(char c : s) {
		sum += c - '0';
	}
	cnt[s.length()][sum]++;
	// cerr << "len = " << s.length() << "; sum = " << sum << endl;
}

int getSum(string s, int i, int j) {
	int sum = 0;
	for(int t = i; t <= j; t++) {
		sum += s[t] - '0';
	}
	// cerr << "i = " << i << "; j = " << j << "; sum = " << sum << endl;
	return sum;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<string>());
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			string s = a[i] + a[j];
			// cerr << "s = " << s << endl;
			int len = s.length();
			if(len & 1) {
				continue;
			}
			// cerr << "len = " << len << endl;
			// cerr << "getSuml = " << getSum(s, 0, len / 2) << endl;
			// cerr << "getSumr = " << getSum(s, 0, len - 1) - getSum(s, 0, len/ 2) << endl;
			if(getSum(s, 0, len / 2 - 1) == getSum(s, 0, len - 1) - getSum(s, 0, len/ 2 - 1)) {
				cerr << a[i] << ' ' << a[j] << endl;
			}
		}
	}
}