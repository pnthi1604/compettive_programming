#include <bits/stdc++.h>
#define ll long long

using namespace std;

void debug(string s, ll val) {
	cerr << s << " = " << val << endl;
}

void debug(string s, vector<ll> a) {
	cerr << "check array " << s << endl;
	for(int i = 0; i < a.size(); i++) {
		cerr << s << "[" << i << "] = " << a[i] << endl;
	}
	cerr << "\nend check array " << s << endl;
}

bool solve(vector<ll> &cof, vector<ll> &ans, ll sum, ll m) {
	ans.assign(cof.size(), 1);
	for(int i = 0; i < cof.size() - 1; i++) {
		ll tmp = sum;
		for(int j = i + 1; j < cof.size(); j++) {
			tmp -= cof[j];
		}
		if(tmp < cof[i])
			return false;
		ans[i] = min(tmp / cof[i], m);
		sum -= ans[i] * cof[i];
	}
	if(sum <= 0 || sum > m)
		return false;
	ans[cof.size() - 1] = sum;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while(q--) {
		ll a, b, m;
		cin >> a >> b >> m;
		if(a == b) {
			cout << 1 << ' ' << a << '\n';
			continue;
		}
		bool ok = false;
		for(int k = 1; k <= 50; k++) {
			ll tmpb = b - (1LL << (k - 1)) * a;
			if(tmpb <= 0)
				break;
			vector<ll> cof(k, 1);
			int p = 0;
			for(int i = k - 2; i >= 0; i--) {
				cof[i] = 1LL << p;
				p++;
			}
			vector<ll> ans;
			ok = solve(cof, ans, tmpb, m);
			if(ok) {
				// debug("ans", ans);
				vector<ll> res(1, a);
				for(int i = 0; i < k; i++) {
					ll sum = 0;
					for(ll x : res)
						sum += x;
					sum += ans[i];
					res.push_back(sum);
				}
				// debug("res", res);
				cout << res.size() << ' ';
				for(ll x : res) {
					cout << x << ' ';
				}
				cout << '\n';
				break;
			}
		}
		if(ok == false) {
			cout << -1 << '\n';
		}
	}
	return 0;
}