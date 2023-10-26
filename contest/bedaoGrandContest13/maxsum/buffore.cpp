#include <bits/stdc++.h>
#define int long long

using namespace std;

const int inf = (int)1e18;

vector<int> calPrefix(vector<int> &a) {
	vector<int> res = a;
	for(int i = 1; i < a.size(); i++)
		res[i] += res[i - 1];
	return res;
}

void check(vector<int> a) {
	for(int x : a) {
		cerr << x << ' ';
	}
	cerr << endl;
}

int sum(vector<int> &a, int l, int r) {
	if(r < l)
		return 0;
	if(l == 0)
		return a[r];
	return a[r] - a[l - 1];
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x : a)
		cin >> x;
	vector<int> preA = calPrefix(a);
	int ans = preA.back();
	for(int &x : a)
		x = -x;
	vector<int> revPreA = calPrefix(a);
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			for(int k = j + 1; k < n; k++) {
				for(int l = k; l < n; l++) {
					ans = max(ans, sum(preA, 0, i - 1) + sum(revPreA, i, j) + sum(preA, j + 1, k - 1) + sum(revPreA, k, l) + sum(preA, l + 1, n - 1));
				}
			}
		}
	}
	cout << ans;
}