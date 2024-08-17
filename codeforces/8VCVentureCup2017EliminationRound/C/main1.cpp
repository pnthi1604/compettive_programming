#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)1e4;
int n;
vector<int> adj[N];
int vis[N];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    auto dfs = [&](auto dfs, int u, int del) -> void {
        vis[u] = del;
        for(int v : adj[u]) {
            if(vis[v]) continue;
            dfs(dfs, v, del);
        }
    };
    int del = 0;
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        dfs(dfs, i, ++del);
    } 
    cout << del;
    return 0;
}