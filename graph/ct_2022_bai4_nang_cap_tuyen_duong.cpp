#include <bits/stdc++.h>
#define ll long long
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
#define all(a) a.begin(), a.end()
#define int ll
//#include "/home/phamngocthi/cp/see.cpp"
using namespace std;
vector<vpii> a;
int n, m, q;
vt d1, d2;
struct way {
    int d1, d2, v;
};

struct cmp {
    bool operator() (way a, way b) const {
        if(a.d1 != b.d1)
            return a.d1 < b.d1;
        if(a.d2 != b.d2)
            return a.d2 < b.d2;
        return a.v < b.v;
    }
};

void djt() {
    set<way,cmp> se;
    se.insert({0, 0, 1});
    while(!se.empty()) {
        way x = *se.begin();
        se.erase(se.begin());
        int u = x.v;
        for(pii y : a[u]) {
            int v = y.first, tv = y.second;
            way delval = {d1[v], d2[v], v};
            bool ok = false;
            if(d1[v] > d1[u] + tv) {
                d1[v] = d1[u] + tv;
                ok = true;
            }
            int tmp = min(d1[u], d2[u] + tv);
            if(d2[v] > tmp)
                d2[v] = tmp, ok = true;
            if(ok) {
                se.insert(delval);
                se.erase(delval);
                se.insert({d1[v], d2[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> q;
    d1.assign(n + 1, inf);
    d2.assign(n + 1, inf);
    a.assign(n + 1, vpii(0));
    for(int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        a[u].push_back({v, t});
    }
    d1[1] = 0;
    d2[1] = 0;
    djt();
    while(q--) {
        int s, t;
        cin >> s >> t;
        cout << min(d1[s], d2[s] + t) << endl;
    }
}
