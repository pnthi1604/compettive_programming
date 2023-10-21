#include <bits/stdc++.h>
#define ll long long
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
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define int ll
#define inf (int)1e18
using namespace std;

struct dsu {
    int n;
    vt par;
    vt sz;

    dsu(int nn) {
        n = nn;
        par.resize(n + 1);
        for(int i = 1; i <= n; i++)
            par[i] = i;
        sz.assign(n + 1, 1);
    }

    int find_par(int x) {
        if(x == par[x])
            return x;
        return par[x] = find_par(par[x]);
    }

    bool union_sets(int x, int y) {
        x = find_par(x);
        y = find_par(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            par[y] = x;
            sz[x] += sz[y];
            return true;
        }
        return false;
    }

    void reset_par() {
        for(int i = 1; i <= n; i++)
            par[i] = find_par(i);
    }

    vtt groups() {
        // returns the list of the "list of the vertices in a connected component".
        reset_par();
        vt leader = par;
        vt id(n + 1, -1);
        int cnt = 1;
        for (int i = 1; i <= n; ++i) {
            if (id[leader[i]] == -1) {
                id[leader[i]] = cnt++;
            }
        }
        vtt result(cnt + 1);
        for (int i = 1; i <= n; ++i) {
            result[id[leader[i]]].push_back(i);
        }
        return result;
    }
};

const int N = 1000;
vt a[N + 1];

signed main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    dsu t(n);
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        t.union_sets(u, v);
    }
    cout << "hi\n";
    vtt res = t.groups();
    int cnt = 1;
    for(vt y : res) {
        if(y.size()) {
            cout << "nhom " << cnt++ << ": ";
            for(int x : y)
                cout << x << ' ';
            cout << endl;
        }
    }
}
