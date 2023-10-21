#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = (int)2e5;
vector<int> prime(maxn + 1);
void sieve(int n) {
	for(int i = 1; i <= n; i++)
		prime[i] = i;
	for(int i = 2; i <= n; i++) {
		if(prime[i] == i) {
			for(int j = 2 * i; j <= n; j += i) {
				prime[j] = i;
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	sieve(n);
	int ans = sqrt(n);
	for(int i = 2; i <= n; i++) {
		map<int,int> cnt;
		int p = i;
		while(prime[p] != p) {
			cnt[prime[p]]++;
			p /= prime[p];
		}
		cnt[p]++;
		int tmpN = n;
		for(auto[p, _cnt] : cnt) {
			tmpN = tmpN / (_cnt & 1 ? p : 1);
		}
		ans += sqrt(tmpN);
	}
	cout << ans;
}