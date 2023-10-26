#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	multiset<pair<int,int>> msL, msR;
	while(q--) {
		char type;
		int l, r;
		cin >> type >> l >> r;
		if(type == '+') {
			msL.insert({l, r});
			msR.insert({r, l});
		} else {
			msL.erase(msL.find({l, r}));
			msR.erase(msR.find({r, l}));
		}
		if(msL.size() <= 1) {
			cout << "NO\n";
		} else {
			int maxL = (*msL.rbegin()).first, minR = (*msR.begin()).first;
			if(maxL > minR) {
				cout << "YES\n";
			} else {
				cout << "NO\n";	
			}
		}
	}
}