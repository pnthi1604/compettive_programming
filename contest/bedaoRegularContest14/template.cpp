#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> f(n);
	f[0] = 1;
	for(int i = 1; i < n; i++) {
		f[i] = f[i - 1] + 1;
		if(i == 1)
			continue;
		else {
			if(f[i] == f[i - 1] + f[i - 2])
				f[i]++;
		}
	}
	for(int i = 0; i < n; i++) {
		cout << f[i] << ' ';
	}
}