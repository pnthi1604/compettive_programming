#include <bits/stdc++.h>
#define int long long
#define inf (int)1e18
using namespace std;
const int N = (int)1e5;
vpii a[N + 1];
int n, m, s; 

void dj() {
    vector<int> dist(n, inf);
    multiset<pair<int,int>> ms;
    ms.insert({0, s});
    dist[s] = 0;
    while(ms.size()) {
        auto[distu, u] = *ms.begin();
        ms.erase(ms.find({distu, u}));
        for(auto[wuv, v] : a[u]) {
            if(dist[v] > distu + wuv) {
                if(ms.find({dist[v], v}) != ms.end())
                    ms.erase(ms.find(dist[v], v));
                dist[v] = distu + wuv;
                ms.insert({dist[v], v});
            }
        }
    } 
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        a[u].push_back({v, w});
    }
    dj();
}
