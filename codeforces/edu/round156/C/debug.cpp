#include <bits/stdc++.h>
#define int long long
using namespace std;

int S(int i, int n) {
	return n * (n + 1) / 2 - i * (i + 1) / 2;
}

bool cmp(pair<char,int> a, pair<char,int> b) {
	if(a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}

bool cmp1(pair<char,int> a, pair<char,int> b) {
	return a.second < b.second;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> s >> n;
		int num;
		// cerr << "n = " << n << '\n';
		for(int i = s.length(); i >= 1; i--) {
			// cerr << "S = " << S(i, s.length()) << '\n';
			if(S(i, s.length()) >= n) {
				num = i;
				break;
			}
			num = i;
		}
		for(int i = s.length(); i >= 1; i--) {
			if(n - i <= 0) {
				break;
			}
			n -= i;
		}
		// cerr << "num = " << num << '\n';
		vector<pair<char,int>> ss;
		for(int i = 0; i < s.length(); i++) {
			ss.push_back({s[i], i});
		}
		sort(ss.begin(), ss.end(), cmp);
		// cerr << "check ss\n";
		// for(auto [c, id] : ss) {
		// 	cerr << "c = " << c << "; id = " << id << '\n';
		// }
		// cerr << "end ss\n";
		sort(ss.begin(), ss.begin() + num, cmp1);
		// cerr << "check ss\n";
		// for(auto [c, id] : ss) {
		// 	cerr << "c = " << c << "; id = " << id << '\n';
		// }
		// cerr << "end ss\n";
		cout << ss[n - 1].first;
	}
}