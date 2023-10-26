#include <bits/stdc++.h>
#define int long long
#define hi cerr << "HIHIHI\n";

using namespace std;

const int inf = (int)1e17;

int n;
vector<int> a;
vector<bool> exist;

struct Data {
	int mx, pre, suf, sum;
};

struct DSU {
	int n;
	vector<int> par;
	vector<Data> best;

	void init(int _n) {
		n = _n;
		par.resize(n);
		best.resize(n);
		for(int i = 0; i < n; i++)
			par[i] = i;
	}

	int findPar(int u) {
		if(u == par[u])
			return u;
		return par[u] = findPar(par[u]);
	}

	int unionSet(int u, int v) {
		if(!(u >= 0 && u < n && v >= 0 && v < n))
			return 0;
		if(exist[u] == false || exist[v] == false)
			return 0;
		u = findPar(u);
		v = findPar(v);
		Data a = best[u], b = best[v];
		Data res;
		res.pre = max(a.pre, a.sum + b.pre);
		res.suf = max(b.suf, b.sum + a.suf);
		res.sum = a.sum + b.sum;
		res.mx = max({a.mx, b.mx, a.suf + b.pre});
		par[v] = u;
		best[u] = res;
		return res.mx;
	}

	int getMax(int u) {
		return best[u].mx;
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n);
	for(int &x : a)
	cin >> x;
	vector<int> qs(n);
	for(int i = 0; i < n; i++) {
		cin >> qs[i];
		qs[i]--;
	}
	reverse(qs.begin(), qs.end());
	DSU d;
	d.init(n);
	exist.assign(n, false);
	int maxCur = 0, maxVal = -inf;
	vector<int> ans;
	for(int x : qs) {
		exist[x] = true;
		maxVal = max(maxVal, a[x]);
		d.best[x] = {max(0LL, a[x]), max(0LL, a[x]), max(0LL, a[x]), a[x]};
		maxCur = max(maxCur, d.getMax(x));
		maxCur = max(maxCur, d.unionSet(x - 1, x));
		maxCur = max(maxCur, d.unionSet(x, x + 1));
		if(maxCur)
			ans.push_back(maxCur);
		else
			ans.push_back(maxVal);
	}
	reverse(ans.begin(), ans.end());
	for(int x : ans) {
		cout << x << '\n';
	}
}
