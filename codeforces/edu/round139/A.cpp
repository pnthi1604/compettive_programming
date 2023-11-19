#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool check(int n) {
	int cnt = 0;
	while(n) {
		int r = n % 10;
		if(r)
			cnt++;
		n /= 10;
		if(cnt > 1)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	const int maxn = 999999;
	vector<int> ans(maxn + 1);
	int cnt = 0;
	for(int i = 1; i <= maxn; i++) {
		if(check(i)) 
			cnt++;
		ans[i] = cnt;
	}
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << ans[n] << '\n';
	}
	return 0;
}