#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)1e5;

struct Node {
	int c[26];
	int cnt, exist;
};

struct Trie {
	int cur;
	vector<Node> nodes;
	void init() {
		nodes.resize(N * 21);
		cur = 0;
		newNode();
	}
	int newNode() {
		nodes[cur].cnt = nodes[cur].exist = 0;
		for(int i = 0; i < 26; i++)
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

int len[N * 21], max_len[N * 21];
int n;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	t.init();
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		t.add(s);
	}
	len[0] = 0;
	auto dfs_len = [&](auto dfs_len, int u) -> void {
		for(int i = 0; i < 26; i++)
			if(t.nodes[u].c[i] != -1) {
				len[t.nodes[u].c[i]] = len[u] + 1;
				dfs_len(dfs_len, t.nodes[u].c[i]);
			}
		max_len[u] = len[u];
		for(int i = 0; i < 26; i++) 
			if(t.nodes[u].c[i] != -1) {
				max_len[u] = max(max_len[u], max_len[t.nodes[u].c[i]]);
			}
	};
	dfs_len(dfs_len, 0);
	auto dfs = [&](auto dfs, int pos, string &res) -> void {
		for(int i = 0; i < t.nodes[pos].exist; i++)
			res += "P";
		for(int i = 0; i < 26; i++) {
			int v = t.nodes[pos].c[i];
			if(v == -1) continue;
			if(max_len[v] < max_len[pos]) {
				res += (char)(i + 'a');
				dfs(dfs, v, res);
			}
		}
		for(int i = 0; i < 26; i++) {
			int v = t.nodes[pos].c[i];
			if(v == -1) continue;
			if(max_len[v] == max_len[pos]) {
				res += (char)(i + 'a');
				dfs(dfs, v, res);
			}
		}
		res += "-";
	};
	string res = "";
	dfs(dfs, 0, res);
	while(res.back() == '-')
		res.pop_back();
	cout << res.size() << endl;
	cout << res;
	return 0;
}