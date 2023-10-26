#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	double n;
	cin >> n;
	if(n > log2(n * n)) {
		cout << "Yes";
	} else {
		cout << "No";
	}
}