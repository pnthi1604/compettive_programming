#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = (int)1e9 + 7;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map<vector<string>,int> cnt;
	int len = n + m;
	for(int i = 0; i < (1 << len); i++) {
		vector<int> id;
		for(int j = 0; j < len; j++) {
			if(i & (1 << j)) {
				id.push_back(j);
			}
		}
		sort(id.begin(), id.end());
		cerr << "check id\n";
		for(int x : id) {
			cerr << x << ' ';
		}
		cerr << "\nend check id\n";
		do {
			vector<string> b(a.begin(), a.end());
			cerr << "\ncheck permutation\n";
			for(int x : id) {
				cerr << x << ' ';
				if(x < n) {
					int row = x;
					int l = 0, r = m - 1;
					while(l < r) {
						swap(b[row][l++], b[row][r--]);
					}
				} else {
					int col = x - n;
					int l = 0, r = n - 1;
					while(l < r) {
						swap(b[l++][col], b[r--][col]);
					}
				}
			}
			cerr << "\nend check permutation\n";
			cnt[b] = 1;
		} while(next_permutation(id.begin(), id.end()));
	}
	int ans = 0;
	for(auto x : cnt) {
		ans += x.second;
	}
	cout << ans;
}