#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = (int)1e6 + 1;
vector<int> prime(maxn);

void sieve(int n) {
	for(int i = 1; i < n; i++)
		prime[i] = i;
	for(int i = 2; i < n; i++) {
		if(prime[i] == i) {
			for(int j = 2 * i; j < n; j += i) {
				prime[j] = i;
			}
		}
	}
}

int solve(int n) {
	int p = prime[n];
	int ans = 1;
	while(n != 1) {
		int cnt = 0;
		while(n % p == 0) {
			n /= p;
			cnt++;
		}
		ans *= (cnt + 1);
		p = prime[n];
	} 
	return ans;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	sieve(n);
	vector<int> f(n);
	for(int i = 1; i < n; i++)
		f[i] = solve(i);
	int ans = 0;
	for(int i = 1; i < n; i++)
		ans += f[i] * f[n - i];
	cout << ans;	
}