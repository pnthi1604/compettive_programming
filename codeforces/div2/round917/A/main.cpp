#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int &x : a) cin >> x;
		int cnt_neg = 0, cnt_0 = 0;
		for(int x : a) cnt_neg += (x < 0), cnt_0 += (x == 0);
		if(cnt_0) {
			cout << 0 << endl;
		} else {
			if(cnt_neg % 2) {
				cout << 0 << endl;
			} else {
				cout << 1 << endl;
				cout << "1 0" << endl;
			}
		}
	}			
	return 0;
}