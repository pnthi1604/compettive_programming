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

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		multiset<int> ms;
		for(int i = 0; i < 3; i++) {
			int x;
			cin >> x;
			ms.insert(x);
		}
		bool ok = false;
		for(int i = 0; i < 4; i++) {
			int mi = *ms.begin();
			int mx = *ms.rbegin();
			ms.erase(ms.find(mx));
			if(mi == mx) {
				ok = true;
				break;
			} else if(i < 3) {
				ms.insert(mi);
				ms.insert(mx - mi);
			}
		}
		if(ok == false) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}