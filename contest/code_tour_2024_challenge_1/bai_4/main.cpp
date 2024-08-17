#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (ll &x : a) cin >> x;
		int cur_index = 0;
		string ans = "NO";
		while (cur_index < n) {
			if (a[cur_index] != 1) {
				cur_index++;
				continue;
			}
			ll power = 1;
			int next_index = -1;
			for(int i = cur_index; i < n; i++) {
				if (power >= a[i])
					power += a[i];
				else {
					for(int j = i + 1; j < n; j++) {
						if (a[j] == 1) {
							next_index = j;
							break;
						}
					}
					if (next_index == -1) next_index = n;
					break;
				}
			}
			if (next_index != -1) {
				cur_index = next_index;
			} else if (next_index == n) {
				break;
			} else {
				bool check = true;
				for(int j = cur_index - 1; j >= 0; j--) {
					if (power >= a[j]) {
						power += a[j];
					} else {
						check = false;
						break;
					}
				}
				if (check)
					ans = "YES";
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}