#include <bits/stdc++.h>
#define int long long

using namespace std;

int dx[8] = {-2, -2, -1, 1, 1, -1, 2, 2};
int dy[8] = {-1, 1, 2, 2, -2, -2, -1, 1};

const int INF = (int)1e18;
const int O = 1100;
const int maxn = 1100;
vector<pair<int,int>> g[maxn + O][maxn + O];
int mx, my, tx, ty;
bool used[maxn + O][maxn + O];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> mx >> my >> tx >> ty;
	mx += O;
	my += O;
	tx += O;
	ty += O;
	int type;
	cin >> type;
	if(type == 1) {
		tx--;
	}
	if(mx == tx && my == ty) {
		cout << "NO";
		return 0;
	}
	queue<pair<pair<int,int>, int>> q;
	q.push({{mx, my}, 0});
	used[mx][my] = true;
	int res = INF;
	while(q.size()) {
		auto[u1, v1] = q.front().first;
		int time = q.front().second;
		q.pop();
		int tmp = tx - u1 - time + 1;
		if(v1 == ty && tmp >= 0 && tmp % 2 == 0) {
			res = min(res, tx - u1 + 1);
		}
		for(int t = 0; t < 8; t++) {
			int u2 = u1 + dx[t], v2 = v1 + dy[t];
			if(u2 >= 0 && u2 < maxn + O && v1 >= 0 && v2 < maxn + O) {
				int newTime = time + 1;
				if(used[u2][v2] == false && (v2 != ty || u2 != tx - newTime)) {
					q.push({{u2, v2}, newTime});
					used[u2][v2] = true;
				}
			}
		}
	}
	if(res != INF) {
		cout << "YES\n" << res;
	} else {
		cout << "NO";		
	}
}
