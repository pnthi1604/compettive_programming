#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";

using namespace std;

vector<string> a(2);
int n = 2, m;
vector<vector<bool>> used;
int dx[3] = {-1, 1, 0};
int dy[3] = {0, 0, 1};

void dfs(int u, int v) {
	used[u][v] = true;
	for(int op = 0; op < 3; op++) {
		int uu = u + dx[op], vv = v + dy[op];
		if(uu >= 0 && uu < n && vv >= 0 && vv < m && used[uu][vv] == false && a[uu][vv] == 'B') {
			dfs(uu, vv);
			break;
		}
	}
}

bool check() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
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
		cin >> m;
		cin >> a[0] >> a[1];
		bool ok = false;
		for(int i = 0; i < n; i++) {
			if(a[i][0] == 'B') {
				used.assign(n, vector<bool>(m, false));
				dfs(i, 0);
				ok = ok || check();
			}
		}
		cout << (ok == true ? "YES\n" : "NO\n");
	}
	return 0;
}