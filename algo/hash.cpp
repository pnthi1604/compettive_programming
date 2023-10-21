#include <bits/stdc++.h>
#define int long long
#define vt vector<int>
#define vtt vector<vt>
#define pii pair<int,int>
#define vpii vector<pii>
#define endl '\n'
#define _sort(a) sort(a.begin(), a.end())
#define bsUp(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
#define bsLow(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
using namespace std;

struct Hash {
    int mod, base, n;
    string s;
    vt h, p;
    Hash(string _s, int _mod, int _base) {
        mod = _mod, base = _base, s = _s, n = s.size();
        p.assign(n + 1, 1);
        h.assign(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * base % mod;
            h[i] = h[i - 1] * base + s[i - 1] - 'a' + 1, h[i] %= mod;
        }
    }

    int getHash(int i, int j) {
        i++, j++;
        return (h[j] - h[i - 1] * p[j - i + 1] + mod * mod) % mod;
    }

    bool same(Hash &hr, int l, int r) {
        if(l >= 0 && l <= r && r < n)  {
            return getHash(l, r) == hr.getHash(n - r - 1, n - l - 1);
        }
        return false;
    }
};

signed main() {
}