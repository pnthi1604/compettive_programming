#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct FT {
	int n;
	vector<int> bit;

	void __init__(int _n) {
		n = _n;
		bit.assign(n + 1, 0);
	}

	void add(int x, int val) {
		for(int i = x + 1; i <= n; i += i & -i) {
			bit[i] += val;
		}
	}

	int get(int x) {
		int res = 0;
		for(int i = x + 1; i >= 1; i -= i & -i) {
			res += bit[i];
		}
		return res;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> h(n), query(q), full_values;
	for(int &x : h) {
		cin >> x;
		full_values.push_back(x);
	}
	for(int &x : query) {
		cin >> x;
		full_values.push_back(x);
	}
	sort(full_values.begin(), full_values.end());
	FT ft;
	ft.__init__((int)full_values.size());
	for(int x : h) {
		int index = lower_bound(full_values.begin(), full_values.end(), x) - full_values.begin();
		ft.add(index, 1);
	}
	for(int x : query) {
		int index = lower_bound(full_values.begin(), full_values.end(), x) - full_values.begin();
		cout << ft.get(0, index) + 1 << "\n";
		ft.add(index, 1);
	}
	return 0;
}
