#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define bit(x, i) ((x >> i) & 1)

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
	void init(int n) {
		nodes.clear();
		nodes.resize(n * 31);
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
	for(int i = 1; i <= n; i++)
	for(int i = 1; i <= k; i++)
		cin >> l[i] >> r[i];
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	for(int i = 1; i <= n; i++) 
		dp[i][1] = (x[i] >= l[1] && x[i] <= r[1]);
	auto dfs = [&](auto dfs, int u, int x_cur, int r, int j) -> int {
		int ans = 0;
		for(int i = 0; i < 2; i++) {
			int v = t.nodes[u].c[i];
			if(v == -1) continue;
			if(bit(r, j)) {
				if(bit(x_cur, j)) {
					if(i == 0 && j - 1 >= 0) {
						ans = (ans + dfs(dfs, v, x_cur, r, j - 1))  % MOD;
					} else {
 						ans = (ans + t.nodes[v].cnt) % MOD;
					}
				} else {
					if(i && j - 1 >= 0) {
						ans = (ans + dfs(dfs, v, x_cur, r, j - 1))  % MOD;
					} else {
						ans = (ans + t.nodes[v].cnt) % MOD;
					}
				}
			} else {
				if(bit(x_cur, j) == i) {
					if(j - 1 >= 0)
						ans = (ans + dfs(dfs, v, x_cur, r, j - 1)) % MOD;
					else
						ans = (ans + t.nodes[v].cnt) % MOD;
				}
			}
		}
		return ans % MOD;
	};
	for(int j = 2; j <= k; j++) {
		t.init(n);
		for(int i = 1; i < j; i++)
			t.add(x[i], dp[i][j - 1]);
		for(int i = j; i <= n; i++) {
			int sumr = dfs(dfs, 0, x[i], r[j], 30);
			int suml = dfs(dfs, 0, x[i], l[j] - 1, 30);
			dp[i][j] = (sumr - suml + MOD) % MOD;
			t.add(x[i], dp[i][j - 1]);
		}
	}
	cout << dp[n][k] % MOD;
	return 0;
}