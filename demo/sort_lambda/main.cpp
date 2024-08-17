#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x : a) cin >> x;
	sort(a.begin(), a.end(), [](int x, int y) {
		return x < y;
	});
	for(int x : a) 
		cout << x << ' ';
	return 0;
}