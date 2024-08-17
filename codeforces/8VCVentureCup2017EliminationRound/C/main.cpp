#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)1e4;
int n;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int ans = n;
    struct DSU {
        int n;
        vector<int> par, sz;
        void init(int _n) {
            n = _n;
            par.resize(n);
            sz.resize(n);
            for(int i = 0; i < n; i++)
                par[i] = i, sz[i] = 1;
        }
        int f(int x) {
            return (x == par[x] ? x : par[x] = f(par[x]));
        }
        bool U(int x, int y) {
            x = f(x), y = f(y);
            if(x == y) return false;
            if(sz[x] < sz[y]) swap(x, y);
            sz[x] += sz[y];
            par[y] = x;
            return true;
        }
    };
    DSU d;
    d.init(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        if(d.U(i, x)) ans--;
    }
    cout << ans;
    return 0;
}