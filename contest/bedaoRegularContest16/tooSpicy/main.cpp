#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, maxVal;
vector<int> a;

bool check(int i, int power) {
	if(power < a[i])
		return false;
	power += a[i];
	int j = (i + 1) % n;
	while(j != i) {
		if(power < a[j])
			return false;
		power += a[j];
		j = (j + 1) % n;
	}
	return true;
}

bool check(int mid) {
	for(int i = 0; i < n; i++) {
		if(check(i, mid))
			return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n);
	for(int &x : a) {
		cin >> x;
		maxVal = max(maxVal, x);
	}
	int l = 0, r = maxVal, res = r;
	while(l <= r) {
		int m = (l + r) / 2;
		if(check(m)) {
			res = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << res;
}