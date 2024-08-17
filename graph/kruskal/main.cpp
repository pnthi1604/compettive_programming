#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)2e5;
int n, m;
vector<int> adj[N];
int par[N];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<pair<int,pair<int,int>>> E;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        E.push_back({w, {u, v}});
    }
    sort(E.begin(), E.end());
    for(int i = 0; i < n; i++) par[i] = i;
    auto findPar = [&](auto findPar, int x) -> int {
        return x == par[x] ? x : (par[x] = findPar(findPar, par[x]));
    };
    vector<pair<int,pair<int,int>>> MST;
    for(pair<int,pair<int,int>> e : E) {
        int w = e.first;
        auto[u, v] = e.second;
        int par_u = findPar(findPar, u);
        int par_v = findPar(findPar, v);
        if(par_u == par_v) continue;
        par[par_u] = par_v;
        MST.push_back({w, {u, v}});
    }
    cerr << "in ket qua" << endl;
    for(pair<int,pair<int,int>> x : MST) {
        int w = x.first;
        auto[u, v] = x.second;
        cerr << "u = " << u << "; v = " << v << "; w = " << w << endl;
    }
    return 0;   
}