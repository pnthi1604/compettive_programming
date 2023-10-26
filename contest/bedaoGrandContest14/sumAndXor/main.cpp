#include <bits/stdc++.h>
#define int long long

using namespace std;

int cntBit(int n) {
	int cnt = 0;
	while(n) {
		n /= 2;
		cnt++;
	}
	return  cnt;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int &x : a)
		cin >> x;
	for(int &x : b)
		cin >> x;
	vector<int> cnt(21, 0);
	for(int x : b) {
		for(int i = 0; i < 21; i++) {
			if(x & (1 << i))
				continue;
			cnt[i]++;
		}
	}
	int ans = 0;
	for(int x : a) {
		int lenBit = cntBit(x);
		for(int i = 0; i < lenBit; i++) {
			if(x & (1 << i)) {
				ans += (1 << i) * cnt[i];
			}
		}
	}
	cout << ans;
}