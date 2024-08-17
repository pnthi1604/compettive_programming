#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

void solve() {
	int m;
	cin >> m;
	map<int,int> p;
	while(m--) {
		int t, x;
		cin >> t >> x;
		if(t == 1) {
			p[x]++;
			// for(int i = 1; i <= 29; i++)
			// 	if(p[i - 1] >= 2) {
			// 		p[i]++;
			// 		p[i - 1] -= 2;
			// 	}
		}
		else {
			// cerr << "check p" << endl;
			// for(int i = 0; i <= 2; i++) cerr << "p[" << i << "] = " << p[i] << endl;
			// cerr << endl;
			for(int i = 29; i >= 0; i--) {
				if(p[i]) {
					int cnt = p[i];
					while(x - (1 << i) >= 0 && cnt)
						x -= (1 << i), cnt--;
				}
			}
			if(x != 0) {
				cout << "NO" << endl;
			} else {
				cout << "YES" << endl;
			}
		}
	}
}
	

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}