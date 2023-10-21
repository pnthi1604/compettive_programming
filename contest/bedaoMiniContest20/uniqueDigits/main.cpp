#include <bits/stdc++.h>
#define int long long

using namespace std;

const int inf = (int)1e18;

int check(int x) {
	vector<bool> cnt(10, 0);
	int res = 0;
	while(x) {
		int r = x % 10;
		x /= 10;
		if(cnt[r])
			return -1;
		cnt[r] = true;
		res += (1 << r);
	}
	return res;
}

bool check(int state1, int state2) {
	return __builtin_popcountll(state1) + __builtin_popcountll(state2) == __builtin_popcountll(state1 ^ state2);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a, state;
		map<int,bool> isExist;
		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			if(isExist[x])
				continue;
			int curState = check(x);
			if(curState == -1)
				continue;
			a.push_back(x);
			state.push_back(curState);
			isExist[x] = true;
		}
		n = a.size();
		vector<int> dp(1 << 10);
		for(int i = 0; i < n; i++) {
			vector<int> newdp(1 << 10);
			for(int mark = 0; mark < (1 << 10); mark++) {
				newdp[mark] = max(newdp[mark], dp[mark]);
				if(check(state[i], mark)) {
					newdp[mark | state[i]] = max(newdp[mark | state[i]], dp[mark] + a[i]);
				}
			}
			for(int mark = 0; mark < (1 << 10); mark++)
				dp[mark] = newdp[mark];
		}
		int res = 0;
		for(int mark = 0; mark < (1 << 10); mark++)
			res = max(res, dp[mark]);
		cout << res << '\n';
	}
}
