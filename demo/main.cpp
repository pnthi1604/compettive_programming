#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)1e6 + 10;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	bitset<N> bs, ans;
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	for(int x : a) {
		bs[x] = 1;
		ans[x] = 1;
	}
	for(int i = 0; i < 100000; i++)
		auto x = (ans & bs);
	// vector<int> res;
	// for(int i = 0; i < n; i++) {
	// 	res.push_back((ans & bs).count());
	// }
	// for(int x : res)
	// 	cout << x << ' ';
	return 0;
}