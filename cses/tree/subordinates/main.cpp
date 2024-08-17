#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)2e5;
vector<int> adj[N];
int n;
int ans[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    auto dfs = [&](auto dfs, int u, int p) -> int {
        int res = 1;
        for(int v : adj[u]) {
            if(v == p) continue;
            res += dfs(dfs, v, u);
        }
        ans[u] = res - 1;
        return res;
    };
    dfs(dfs, 0, -1);
    for(int i = 0; i < n; i++) 
        cout << ans[i] << ' ';
    return 0;
}