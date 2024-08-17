#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";

using namespace std;

vector<vector<int>> adj;
int n, ans;
vector<int> pl, pr, dp, par;
vector<char> node;

void dfs(int u) {
    int p = par[u];
    if(p >= 1 && u >= 1) {   
        if((pl[p] == u && node[p] == 'L') || (pr[p] == u && node[p] == 'R')) {
            dp[u] = dp[p];
        } else {
            dp[u] = dp[p] + 1;
        }
    }
    if(adj[u].size() == 0) {
        ans = min(ans, dp[u]);
    } else {
        for(int v : adj[u]) {
            dfs(v);
        } 
    }
}

void solve() {
    cin >> n;
    adj.resize(n + 1);
    pl.resize(n + 1);
    pr.resize(n + 1);
    node.resize(n + 1);
    dp.resize(n + 1);
    par.resize(n + 1);
    ans = (int)1e9;
    for(int i = 1; i <= n; i++) {
        cin >> node[i];
    }
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        cin >> pl[i] >> pr[i];
        if(pl[i]) {
            adj[i].push_back(pl[i]);
            par[pl[i]] = i;
        }
        if(pr[i]) {
            adj[i].push_back(pr[i]);
            par[pr[i]] = i;
        }
    }
    dfs(1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();        
    }
}