#include <bits/stdc++.h>
#define hi cerr << "HIHIHI\n";
using namespace std;

const long long INF = (long long)1e17;
vector<long long> a;
vector<long long> dp;
vector<vector<int>> adj;
long long n;
long long ans = -INF;

void upd(long long &mx1, long long &mx2, long long val) {
    if(val >= mx1) {
        swap(mx1, mx2);
        mx1 = val;
    } else if(val > mx2) {
        mx2 = val;
    }
}

long long dfs(int u, int p) {
    long long res = a[u];
    for(int v : adj[u]) {
        if(v != p) {
            long long sum = dfs(v, u);
            res += sum;
            dp[u] = max(dp[u], dp[v]);
        }
    }
    dp[u] = max(dp[u], res);
    long long mx1 = -INF, mx2 = -INF;
    for(int v : adj[u]) {
        if(v != p) {
            upd(mx1, mx2, dp[v]);
        }
    }
    if(mx1 != -INF && mx2 != -INF) {
        ans = max(ans, mx1 + mx2);
    }
    return res; 
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    adj.resize(n);
    dp.assign(n, -INF);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    if(ans == -INF) {
        cout << "Impossible";
    } else {
        cout << ans;
    }
}