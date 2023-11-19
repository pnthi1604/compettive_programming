#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)1e17;
int n;
vector<vector<int>> adj;
vector<int> a;
vector<long long> dp;
long long ans = -INF;

void reset() {
    a.resize(n);
    adj.resize(n);
    dp.assign(n, -INF);
}

long long dfs(int u, int p) {
    long long sum = a[u];
    for(int v : adj[u]) {
        if(v != p) {
            sum += dfs(v, u);
            dp[u] = max(dp[u], dp[v]);
        }
    }
    dp[u] = max(dp[u], sum);
    long long mx1 = -INF, mx2 = -INF;
    for(int v : adj[u]) {
        if(v != p) {
            if(dp[v] >= mx1) {
                swap(mx1, mx2);
                mx1 = dp[v];
            } else if(dp[v] > mx2) {
                mx2 = dp[v];
            }
        }
    }
    if(mx1 != -INF && mx2 != -INF) {
        ans = max(ans, mx1 + mx2);
    }
    return sum;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    reset();
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    if(ans != -INF) {
        cout << ans;
    } else {
        cout << "Impossible";
    }
}