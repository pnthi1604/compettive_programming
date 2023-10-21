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
#define hi cout << "hi\n";
using namespace std;

const int nmax = (int)1e5 + 1;

struct Hash {
    int n, mod, base;
    vt h, p;
    string s;

    void init(string _s, int _mod, int _base) {
        s = _s;
        n = s.length();
        mod = _mod, base = _base;
        h.resize(n + 1);
        p.resize(n + 1);
        p[0] = 1;
        h[0] = 0;
        for(int i = 1; i <= n; i++) {
            h[i] = h[i - 1] + s[i - 1] - 'a' + 1 + p[i - 1];
            h[i] %= mod;
            p[i] = p[i - 1] * base % mod;
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
}

//DON'T LET THE NUMBER OVERFLOW OR THE MOD GO NEGATIVE :V