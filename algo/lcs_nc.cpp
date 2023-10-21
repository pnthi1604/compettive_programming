#include <bits/stdc++.h>
#define int long long
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define ii pair<int,int>
#define vii vector<ii>
#define endl '\n'
#define _sort(a) sort(a.begin(), a.end())
#define bsUp(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
#define bsLow(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define rev(a) reverse(a.begin(), a.end())
#define all(a) a.begin(), a.end()
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define inf (int)1e18
//#include "/home/phamngocthi/cp/see.cpp"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    if(s.length() < t.length())
        swap(s, t);
    int n_s = s.size(), n_t = t.size();
    s = ' ' + s;
    t = ' ' + t;
    vtt next(n_s + 2, vt(257, n_s + 1));
    for(int i = n_s; i >= 1; i--) {
        for(int j = 0; j <= 256; j++)
            if(s[i] == j)
                next[i][j] = i;
            else
                next[i][j] = next[i + 1][j];
    }
    vtt f(n_t + 1, vt(n_t + 1, n_s + 1));
    for(int i = 0; i <= n_t; i++)
        f[i][0] = 0;
    int res = 0;
    for(int k = 1; k <= n_t; k++) {
        for(int i = k; i <= n_t; i++) {
            f[i][k] = f[i - 1][k];
            if(f[i - 1][k - 1] + 1 <= n_s)
                f[i][k] = min(f[i][k], next[f[i - 1][k - 1] + 1][t[i]]);
            if(f[i][k] <= n_s) {
                //in(i);
                //in(k);
                //in(f[i][k]);
                res = max(res, k);
            }
        }
    }
    cout << res;
}
