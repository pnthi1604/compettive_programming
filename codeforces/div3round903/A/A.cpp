#include <bits/stdc++.h>
#define ll long long
#define infInt (int)1e9 + 1
// #define infLL 0x3f3f3f3f3f3f
#define infLL (int)1e17
#define endl '\n'
#define all(a) a.begin(), a.end()
#define _sort(a) sort(all(a))
#define bsUp(a, x) upper_bound(all(a), x) - a.begin()
#define bsLow(a, x) lower_bound(all(a), x) - a.begin()
#define rev(a) reverse(all(a))
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define int ll
#define hi ;
using namespace std;

bool check(string &a, string &b) {
	for(int i = 0; i + b.length() <= a.length(); i++) {
		if(a.substr(i, b.length()) == b)
			return true;
	}
	return false;
}

signed main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		string a, b;
		cin >> a >> b;
		int cnt = 0;
		while((1 << cnt) <= max((1 << n), (1 << m))) {
			if(check(a, b)) {
				break;
			} else {
				cnt++;
				a += a;
			}
		}
		if(check(a, b)) {
			cout << cnt << endl;
		} else {
			cout << -1 << endl;
		}
	}
}