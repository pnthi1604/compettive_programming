#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> d[4] = {
	{1, 1, 1},
	{1, 1, 2},
	{1, 2, 2},
	{2, 2, 2}
};

bool check(int n, int idx) {
	if(n - idx - 3 >= 0 && (n - idx - 3) % 3 == 0) {
		int val = (n - idx - 3) / 3;
		cout << "YES\n";
		for(int j = 0; j < 3; j++) {
			if(j < 2) {
				cout << d[idx][j] << ' ';
			} else {
				cout << d[idx][j] + val * 3 << ' ';
			}
		}
		cout << '\n';
		return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		bool ok = false;
		for(int i = 0; i < 4; i++) {
			if(check(n, i) == true) {
				ok = true;
				break;
			}
		}
		if(ok == false) {
			cout << "NO\n";
		} 
	}
}