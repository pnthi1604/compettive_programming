#include <bits/stdc++.h>
#define int long long
using namespace std;

int S(int i, int n) {
	return n * (n + 1) / 2 - i * (i + 1) / 2;
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
		for(int i = s.length(); i >= 1; i--) {
			if(S(i - 1, s.length()) >= n) {
				num = i;
				break;
			}
		}
		for(int i = s.length(); i >= 1; i--) {
			if(n - i <= 0) {
				break;
			}
			n -= i;
		}
		string ss = "";
		multiset<pair<char,int>> ms;
		int i;
		for(i = 0; s.length() - i >= num; i++) {
			ms.insert({s[i], i});
		}
		int curId = 0;
		for(i; i < s.length(); i++) {
			auto[c, id] = *ms.begin();
			ss += c;
			while(curId <= id) {
				ms.erase(ms.find({s[curId], curId}));
				curId++;
			}
			ms.insert({s[i], i});
		}
		auto[c, id] = *ms.begin();
		ss += c;
		cout << ss[n - 1];
	}
}