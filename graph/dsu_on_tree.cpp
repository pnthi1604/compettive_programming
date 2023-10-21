#include <bits/stdc++.h>
#define ll long long
#define infInt (int)1e9 + 1
// #define infLL 0x3f3f3f3f3f3f
#define infLL (int)1e17
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define vtttt vector<vttt>
#define pii pair<int, int>
#define vpii vector<pii>
#define endl '\n'
#define all(a) a.begin(), a.end()
#define _sort(a) sort(all(a))
#define bsUp(a, x) upper_bound(all(a), x) - a.begin()
#define bsLow(a, x) lower_bound(all(a), x) - a.begin()
#define rev(a) reverse(all(a))
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define int ll
// #define in(a); ; 
// #define hi ;
#include "/home/phamngocthi/cp/see.cpp"
using namespace std;

int n, m;
vtt adj, vec;
vt sz, color, cnt;

void dfsSize(int u, int p) {
    sz[u] = 1;
    for(int v : adj[u]) {
        if(v == p)
            continue;
        dfsSize(v, u);
        sz[u] += sz[v];
    }
}

void dfs(int u, int p, int keep) {
    int mx = -1, bigChild = -1;
    for(int v : adj[u]) {
        if(v == p)
            continue;
        if(mx < sz[v]) {
            mx = sz[v];
            bigChild = v;
        }
    }
    for(int v : adj[u]) {
        if(v == p)
            continue;
        if(v != bigChild) {
            dfs(v, u, 0);
        }
    }
    if(bigChild != -1) {
        dfs(bigChild, u, 1);
        swap(vec[u], vec[bigChild]);
    }
    vec[u].push_back(u);
    cnt[color[u]]++;
    for(int v : adj[u]) {
        if(v != p && v != bigChild) {
            for(int x : vec[v]) {
                cnt[color[x]]++;
                vec[u].push_back(x);
            }
        }
    }
    cout << "cay con goc " << u << " co so dinh co mau 1 la: " << cnt[1] << endl;
    if(keep == 0) {
        for(int v : vec[u]) {
            cnt[color[v]]--;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m;
    adj.assign(n, vt());
    sz.assign(n, 0);
    vec.assign(n, vt());
    cnt.assign(n + 1, 0);
    color.resize(n);
    dfsSize(0, -1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        cin >> color[i];
    }
    dfs(0, -1, 0);
}