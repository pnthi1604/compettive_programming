#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'
#define bit(x, i) ((x >> i) & 1)
#define int ll

using namespace std;

const int N = (int)1e5;
const int max_char = 2;
const int MOD = (int)1e9 + 7;

struct Node {
	int cnt;
	int c[2];
};

struct Trie {
	vector<Node> nodes;
	int cur;
	void init() {
		nodes.resize(N * 100);
		cur = 0;
		newNode();
	}
	int newNode() {
		nodes[cur].c[0] = nodes[cur].c[1] = -1;
		nodes[cur].cnt = 0;
		return cur++;
	}
	void add(int n, int val) {
		int pos = 0;
		for(int i = 30; i >= 0; i--) {
			int biti = bit(n, i);
			if(nodes[pos].c[biti] == -1)
				nodes[pos].c[biti] = newNode();
			pos = nodes[pos].c[biti];
			nodes[pos].cnt += val;
			nodes[pos].cnt %= MOD;
		}
	}
} t;
int n, k;
int a[N], x[N];
int l[N], r[N];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	x[1] = a[1];
	for(int i = 2; i <= n; i++)
		x[i] = a[i] ^ x[i - 1];
	cerr << "check x" << endl;
	for(int i = 1; i <= n; i++)
		cerr << "x[" << i << "] = " << x[i] << endl;
	for(int i = 1; i <= k; i++)
		cin >> l[i] >> r[i];
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
	for(int i = 1; i <= n; i++) 
		dp[i][1] = (x[i] >= l[1] && x[i] <= r[1]);
	auto dfs = [&](auto dfs, int u, int x_cur, int r, int j) -> int {
		if(j == -1) return 1;
		int ans = 0;
		// cerr << "x_cur = " << x_cur << endl;
		// cerr << "r = " << r << endl;
		for(int i = 0; i < 2; i++) {
			int v = t.nodes[u].c[i];
			if(v == -1) continue;
			// cerr << "bitr = " << bit(r, j) << endl;
			// cerr << "bit_x_cur = " << bit(x_cur, j) << endl;
			if(bit(r, j)) {
				if(bit(x_cur, j)) {
					if(i == 0) {
						cerr << 1 << endl;
						ans = (ans + dfs(dfs, v, x_cur, r, j - 1))  % MOD;
					} else {
						cerr << 2 << endl;
 						ans = (ans + t.nodes[v].cnt) % MOD;
					}
				} else {
					if(i) {
						cerr << 3 << endl;
						int tmp = dfs(dfs, v, x_cur, r, j - 1);
						// cerr << "j - 1 = " << j - 1 << endl;
						// cerr << "ket qua = " << tmp << endl;
						ans = (ans + dfs(dfs, v, x_cur, r, j - 1))  % MOD;
					} else {
						cerr << 4 << endl;
						ans = (ans + t.nodes[v].cnt) % MOD;
					}
				}
			} else {
				if(bit(x_cur, j) == i) {
					ans = (ans + dfs(dfs, v, x_cur, r, j - 1)) % MOD;
				}
			}
		}
		return ans % MOD;
	};
	for(int j = 2; j <= k; j++) {
		t.init();
		for(int i = 1; i < j; i++)
			if(dp[i][j - 1] != -1) {
				t.add(x[i], dp[i][j - 1]);
				// cerr << "da them x[" << i << "]" << endl;
			}
		for(int i = j; i <= n; i++) {
			int sumr = dfs(dfs, 0, x[i], r[j], 30);
			int suml = dfs(dfs, 0, x[i], l[j] - 1, 30);
			cerr << "i = " << i << endl;
			cerr << "j = " << j << endl;
			cerr << "r = " << r[j] << endl;
			cerr << "l = " << l[j] << endl;
			cerr << "sumr = " << sumr << endl;
			cerr << "suml = " << suml << endl;
			dp[i][j] = (sumr - suml + MOD) % MOD;
			if(dp[i][j - 1] != -1) {
				t.add(x[i], dp[i][j - 1]);
				cerr << "da them x[" << i << "]" << endl;
			}
		}
	}
	cerr << "check dp" << endl;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			cerr << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
		}
	}
	cout << dp[n][k] % MOD;
	return 0;
}