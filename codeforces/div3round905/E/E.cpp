#include <bits/stdc++.h>
#define int long long

using namespace std;

struct MyData {
	int val, pow;
};

int d(int a, int b) {
	if(a % b == 0)
		return a / b;
	return a / b + 1;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int &x : a)
			cin >> x;
		vector<MyData> b(n);
		b[0] = {a[0], 0};
		int ans = 0;
		for(int i = 1; i < n; i++) {
			auto[vala, xa] = b[i - 1];
			auto[valb, xb] = make_pair(a[i], 0);
			while(vala < valb && (xa - 1) >= 0) {
				vala *= 2;
				xa--;
			}
			xb = xa;
			while((1 << (xb - xa)) < d(vala, valb)) {
				xb++;
			}
			b[i] = {a[i], xb};
		}
		// cerr << "check array b\n";
		for(int i = 0; i < n; i++) {
			auto[val, p] = b[i];
			ans += p;
			// cerr << val << ' ' << p << endl;
		}
		// cerr << "\nend check b\n";
		cout << ans << '\n';
	}
}