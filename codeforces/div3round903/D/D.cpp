#include <bits/stdc++.h>
#define int long long

using namespace std;

void cnt(map<int,int> &m, int n) {
	for(int i = 2; i * i <= n; i++) {
		while(n % i == 0) {
			m[i]++;
			n /= i;
		}
	}
	if(n != 1)
		m[n]++;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		map<int,int> m;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt(m, x);
		}
		bool ok = true;
		for(auto x : m)
			if(x.second % n != 0)
				ok = false;
		if(ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}