#include <bits/stdc++.h>
#define int long long
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
#define all(a) a.begin(), a.end()
using namespace std;
const int N = (int)3e4 + 1;
bool used[N];
int root[N], active[N];
stack<int> s;

void in(int n, int m, vtt &adj) {
    adj.assign(n + 1, vt());
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        root[i] = i, used[i] = false;
}

int find(int v) {
    return v == root[v] ? v : root[v] = find(root[v]);
}

void dfs(int u, vtt &adj) {
    used[u] = true;
    s.push(u);
    for(int v : adj[u]) {
        if(used[v]) {
            v = find(active[v]);
            while(s.top() != v) {
                root[find(s.top())] = v;
                s.pop();
            }
        }
    }
    for(int v : adj[u]) {
        if(!used[v])
            active[u] = v, dfs(v, adj);
    }
    if(s.top() == u) s.pop();
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vtt adj;
    in(n, m, adj);
    for(int i = 1; i <= n; i++)
        if(!used[i])
            dfs(i, adj);
    vt cnt(n + 1, 0);
    for(int i = 1; i <= n; i++) 
        cnt[find(i)]++;
    cout << (m == 0 ? 0 : *max_element(all(cnt))) + 1;
}