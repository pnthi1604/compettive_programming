#include <bits/stdc++.h>
#define int long long

using namespace std;

int kanade(vector<int> &a) {
	int maxCurId = 0, maxLast = -(int)1e18;
	for(int i = 0; i < a.size(); i++) {
		maxCurId += a[i];
		if(maxLast < maxCurId) {
			maxLast = maxCurId;
		}
		if(maxCurId < 0)
			maxCurId = 0;
	}
	return maxCurId;
}

vector<int> calPrefix(vector<int> &a) {
	vector<int> res = a;
	for(int i = 1; i < a.size(); i++) {
		res[i] += res[i - 1];
	}
	return res;
}

int sum(vector<int> &a, int i, int j) {
	if(i == 0)
		return a[j];
	return a[j] - a[i - 1];
}

int kanade2D(vector<vector<int>> &a) {
	int n = a.size(), m = a[0].size();
	vector<vector<int>> prefixSum = a;
	for(int i = 0; i < n; i++)
		prefixSum[i] = calPrefix(prefixSum[i]);
	int ans = -(int)1e18;
	for(int j1 = 0; j1 < m; j1++) {
		for(int j2 = j1; j2 < m; j2++) {
			int maxCurId = 0, maxLast = -(int)1e18;
			for(int i = 0; i < n; i++) {
				maxCurId += sum(prefixSum[i], j1, j2);
				if(maxCurId > maxLast) {
					maxLast = maxCurId;
				}
				if(maxCurId < 0) {
					maxCurId = 0;
				}
			}
			ans = max(ans, maxLast);
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	cout << kanade2D(a);
}