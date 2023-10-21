#include <bits/stdc++.h>
#define int long long
#define inf (int)1e18
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define pii pair<int,int>
#define vpii vector<pii>
#define endl '\n'
#define _sort(a) sort(a.begin(), a.end())
#define bsUp(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
#define bsLow(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define rev(a) reverse(a.begin(), a.end())
using namespace std;
//low[to] <= tin[v]: dinh to hoac con cua to co back-edge
//den v (low[to] == tin[v]) hoac to tien cua v
//(v, to) la bridge khi low[to] > tin[v]
const int N = (int)1e5;
vector<bool> used(N + 1);
vt tin(N + 1, -1), low(N + 1, -1);
int timer;

void dfs(int u, int p = -1) {
    tin[u] = low[u] = timer++;
    for(int v : a[u]) {
        if(v == p)
            continue;
        if(tin[v] != -1)
            low[u] = min(low[u], tin[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u])
                is_bridge(u, v);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
}
