#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";

using namespace std;

int dx[3] = {-1, 1, 0};
int dy[3] = {0, 0, 1};
vector<string> a(2);
int n;
vector<vector<bool>> used;

void reset() {
	used.assign(2, vector<bool>(n, false));
}

void dfs(int u, int v) {
	used[u][v] = true;
	for(int op = 0; op < 3; op++) {
		int uu = u + dx[op], vv = v + dy[op];
		if(uu >= 0 && uu < 2 && vv >= 0  && vv < n && used[uu][vv] == false && a[uu][vv] == 'B') {
			dfs(uu, vv);
			break;
		}
	}
}

bool check() {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 'B' && used[i][j] == false) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		reset();
		cin >> a[0] >> a[1];
		bool ok = false;
		for(int i = 0; i < n; i++) {
			if(a[0][i] == 'B' || a[1][i] == 'B') {
				if(a[0][i] == 'B') {
					dfs(0, i);
					ok = ok || check();
					reset();
				}
				if(a[1][i] == 'B') {
					dfs(1, i);
					ok = ok || check();
				}
				break;
			}
		}
		if(ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}