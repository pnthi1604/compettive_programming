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
}

int getSum(string s, int i, int j) {
	int sum = 0;
	for(int t = i; t <= j; t++) {
		sum += s[t] - '0';
	}
	return sum;
}

bool cmp(string a, string b) {
	return a.length() > b.length();
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		solve(a[i]);
	}
	sort(a.begin(), a.end(), cmp);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		string s = a[i];
		int l = s.length();
		ans += (cnt[l][getSum(s, 0, l - 1)]) * 2 - 1;
		cnt[l][getSum(s, 0, l - 1)]--;
		if(l <= 2) {
			continue;
		}
		if(l == 3) {
			if(getSum(s, 0, 1) > getSum(s, 2, 2)) {
				ans += cnt[1][getSum(s, 0, 1) - getSum(s, 2, 2)];
			}
			if(getSum(s, 1, 2) > getSum(s, 0, 0)) {
				ans += cnt[1][getSum(s, 1, 2) - getSum(s, 0, 0)];
			}
		} else if(l == 4) {
			if(getSum(s, 0, 2) > getSum(s, 3, l - 1)) {
				ans += cnt[2][getSum(s, 0, 2) - getSum(s, 3, l - 1)];
			}
			if(getSum(s, 1, 3) > getSum(s, 0, 0)) {
				ans += cnt[2][getSum(s, 1, 3) - getSum(s, 0, 0)];
			}
		} else {
			if(getSum(s, 0, 2) > getSum(s, 3, l - 1)) {
				ans += cnt[1][getSum(s, 0, 2) - getSum(s, 3, l - 1)];
			}
			if(getSum(s, 2, 4) > getSum(s, 0, 1)) {
				ans += cnt[1][getSum(s, 2, 4) - getSum(s, 0, 1)];
			}
			if(getSum(s, 0, 3) > getSum(s, 4, l - 1)) {
				ans += cnt[3][getSum(s, 0, 3) - getSum(s, 4, l - 1)];
			}
			if(getSum(s, 1, 4) > getSum(s, 0, 0)) {
				ans += cnt[3][getSum(s, 1, 4) - getSum(s, 0, 0)];
			}
		}
	}
	cout << ans << '\n';
}