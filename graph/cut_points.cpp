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
const int N = (int)1e5;
vt a[N + 1];
int timer;
vt low(N + 1, -1), tin(N + 1, -1);

void dfs(int u, int p = -1) {
    low[u] = tin[u] = timer++;
    int childs = 0;
    for(int v : a[u]) {
        if(tin[v] != -1) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= tin[u] && p != -1)
                is_cutpoint(v);
            ++childs;
        }
    }
    if(p == -1 && childs >= 2)
        is_cutpoint(v);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
}
