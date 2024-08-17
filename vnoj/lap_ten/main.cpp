#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)1e5;
const int max_char = 26;

struct Node {
	int cnt, exist;
	int c[max_char + 1];
};

struct Trie {
	int cur;
	vector<Node> nodes;
	void init() {
		nodes.resize(N);
		cur = 0;
		newNode();
	}
	int newNode() {
		nodes[cur].cnt = nodes[cur].exist = 0;
		for(int i = 0; i < max_char; i++)
			nodes[cur].c[i] = -1;
		return cur++;
	}
	void add(string s) {
		int pos = 0;
		for(char c : s) {
			int x = c - 'a';
			if(nodes[pos].c[x] == -1)
				nodes[pos].c[x] = newNode();
			pos = nodes[pos].c[x];
			nodes[pos].cnt++;
		}
		nodes[pos].exist++;
	}
} t;

int n;
int d[N];
multiset<int> dp[N];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	int ans = 0;
	t.init();
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		t.add(s);
		ans += s.length();
	}
	auto dfs = [&](auto dfs, int u) -> void {
		if(t.nodes[u].exist) {
			dp[u].insert(d[u]);
		}
		for(int i = 0; i < max_char; i++) {
			int v = t.nodes[u].c[i];
			if(v == -1) continue;
			d[v] = d[u] + 1;
			dfs(dfs, v);
			if(dp[u].size() < dp[v].size()) swap(dp[u], dp[v]);
			for(int x : dp[v])
				dp[u].insert(x);
			dp[v].clear();
		}
		if(t.nodes[u].exist == 0 && dp[u].size() && u != 0) {
			auto it = prev(dp[u].end());
			ans -= *it - d[u];
			dp[u].erase(it);
			dp[u].insert(d[u]);
		}
	};
	dfs(dfs, 0);
	cout << ans;
	return 0;
}
