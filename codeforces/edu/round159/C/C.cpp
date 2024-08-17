#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = (int)1e9;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x : a) cin >> x;
	if(n == 1) {
		cout << "1\n";
		return;
	}
	int maxVal = *max_element(a.begin(), a.end());
	vector<int> sub;
	int d = 0;
	for(int x : a) {
		if(x == maxVal) continue;
		sub.push_back(maxVal - x);
		d = __gcd(d, maxVal - x);
	}
	// cerr << "d = " << d << endl;
	ll ans = 0;
	for(int i = 0; i < sub.size(); i++) {
		sub[i] /= d;
		ans += sub[i];
	}
	sort(sub.begin(), sub.end());
	// cerr << "check sub" << endl;
	// for(int x : sub) 
	// 	cerr << x << ' ';
	// cerr << endl;
	int an = INF;
	if(sub[0] > 1)
		an = maxVal - 1 * d;
	else {
		for(int i = 0; i < sub.size() - 1; i++) {
			if(sub[i + 1] - sub[i] >= 2) {
				an = maxVal - (sub[i] + 1) * d;
				break;
			}
		}
	}
	// cerr << "an = " << an << endl;
	if(an == INF) {
		ans += n;
	} else {
		ans += (maxVal - an) / d;
	}
	cout << ans << '\n';
}			

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}