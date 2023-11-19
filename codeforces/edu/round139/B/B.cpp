#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		map<string,int> cnt;
		for(int i = 0; i + 1 < n; i++) {
			string tmp = s.substr(i, 2);
			cnt[tmp]++;
		}
		bool ok = false;
		for(int i = 0; i < n - 1; i++) {
			string tmp = s.substr(i, 2);
			string tmp1 = "", tmp2 = "";
			if(i - 1 >= 0)
				tmp1 = s.substr(i - 1, 2);
			if(i + 2 < n)
				tmp2 = s.substr(i + 1, 2);
			cnt[tmp1]--;
			cnt[tmp2]--;
			cnt[tmp]--;
			if(cnt[tmp] != 0) {
				ok = true;
				break;
			}
			cnt[tmp]++;
			cnt[tmp1]++;
			cnt[tmp2]++;
		}
		cout << (ok == true ? "YES\n" : "NO\n");
	}
	return 0;
}