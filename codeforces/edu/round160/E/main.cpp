#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = 50, INF = (int)1e9;
int a[N][N];
int aa[N], bb[N];
int n, m;
int dq(int i, int j, vector<int> &A, vector<int> &B) {
	if(i != 0 && A[i - 1] != aa[i - 1]) return INF;
	if(!(i < n && j < m)) {
		for(int i = 0; i < n; i++)
			if(A[i] != aa[i]) return INF;
		for(int i = 0; i < m; i++)
			if(B[i] != bb[i]) return INF;
		return 0;
	}
	int ans = INF;
	if(a[i][j] == 0) {
		int newj = (j + 1) % m, newi = i;
		if(newj == 0) newi = newi + 1;
		ans = min(ans, dq(newi, newj, A, B));
		if(A[i] + 1 <= aa[i] && B[j] + 1 <= bb[i]) {
			A[i]++;
			B[j]++;
			ans = min(ans, 1 + dq(newi, newj, A, B));
			A[i]--;
			B[j]--;
		}
	} else {
		int newj = (j + 1) % m, newi = i;
		if(newj == 0) newi = newi + 1;
		ans = min(ans, 1 + dq(newi, newj, A, B));
		if(A[i] + 1 <= aa[i] && B[j] + 1 <= bb[i]) {
			A[i]++;
			B[j]++;
			ans = min(ans, dq(newi, newj, A, B));
			A[i]--;
			B[j]--;
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) 
			cin >> a[i][j];
	for(int i = 0; i < n; i++) cin >> aa[i];
	for(int j = 0; j < m; j++) cin >> bb[j];
	vector<int> A(n, 0), B(m, 0);
	int ans = dq(0, 0, A, B);
	cout << (ans == INF ? -1 : ans);
	return 0;
}