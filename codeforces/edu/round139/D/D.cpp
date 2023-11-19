#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

const ll INF = (ll)1e18;
const int N = (int)1e7;
vector<int> prime(N + 1);

void sieve() {
	for(int i = 1; i <= N; i++) {
		prime[i] = i;
	}
	for(int i = 2; i <= N; i++) {
		if(prime[i] == i) {
			for(int j = 2 * i; j <= N; j += i) {
				prime[j] = i;
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	sieve();
	int n;
	cin >> n;
	while(n--) {
		int x, y;
		cin >> x >> y;
		if(x < y)
			swap(x, y);
		int d = gcd(x, y);
		if(d != 1) {
			cout << 0 << '\n';
		} else {
			int k = x - y;
			if(k == 1) {
				cout << "-1\n";
				continue;
			}
			int res = INF;
			int p = prime[k];
			while(p != k) {
				res = min(res, p - (y % p));
				k /= p;
				p = prime[k];
			}
			if(k != 1) {
				res = min(res, k - (y % k));
			}
			cout << res << '\n';
		}
	}
	return 0;
}