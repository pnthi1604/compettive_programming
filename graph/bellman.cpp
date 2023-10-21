#include <bits/stdc++.h>
#define ll long long
#define inf (ll)(1e18)
 
using namespace std;
 
ll n, m, q, g[501][501];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            g[i][j] = inf;
    while(m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }
    for(int i = 1; i <= n; i++) g[i][i] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++) {
                g[j][k] = g[k][j] = min(g[j][k], g[j][i] + g[i][k]);
            }
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << (g[a][b] == inf ? -1 : g[a][b]) << '\n';
    }
    return 0;
}