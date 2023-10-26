#include <bits/stdc++.h>
#define int long long

using namespace std;

int sumArray(vector<int> &a, int i, int j) {
	int res = 0;
	for(int k = i; k <= j; k++)
		res += a[k];
	return res;
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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int &x : a)
		cin >> x;
	for(int &x : b)
		cin >> x;
	a = calPrefix(a);
	b = calPrefix(b);
	vector<vector<int>> c(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i <= j) {
				c[i][j] = sum(a, i, j);
			} else {
				c[i][j] = sum(b, j, i);
			}
 		}
	}
	cout << kanade2D(c);
}