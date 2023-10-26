#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = (int)1e5;
const int inf = (int)1e18;
int sum = 0;
vector<int> a, b;
int n;

bool dp(int suma) {
	if(suma < 0)
		return false;
	bitset<10 * maxn> can, can1, can2;
	can[0] = 1;
	for(int i = 0; i < n; i++) {
		can[a[i]] = 1;
		can[b[i]] = 1;
		can = can | ((can << a[i]) | (can << b[i]));
	}
	return can[suma];
}

bool solve(int mid) {
	int suma1 = (sum - mid) / 2;
	int suma2 = (sum + mid) / 2;
	return dp(suma2) || dp(suma1);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n);
	for(int &x : a)
		cin >> x;
	b.resize(n);
	for(int &x : b)
		cin >> x;
	for(int i = 0; i < n; i++) {
		sum += a[i] + b[i];
	}
	vector<int> val;
	for(int i = (sum & 1); i <= 10 * maxn; i += 2)
		val.push_back(i);
	int l = 0, r = val.size() - 1, res = val.back();
	while(l <= r) {
		int mid = (l + r) / 2;
		if(solve(val[mid])) {
			res = val[mid];
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << res;
}