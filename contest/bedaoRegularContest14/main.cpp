#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	bitset<(int)1e7> can;
	can[0] = 1;
	a[0] = 1;
	can = can | (can << 1);
	for(int i = 1; i < n; i++) {
		for(int j = a[i - 1] + 1; j <= n * (int)sqrt(n); j++) {
			if(can[j])
				continue;
			a[i] = j;
			cerr << "j = " << j << endl;
			can = can | (can << j);
			break;
		}
	}
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
}