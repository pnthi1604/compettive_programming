#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f
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
// #include "/home/phamngocthi/cp/see.cpp"
using namespace std;

const int N = (int)1e6, mod = (int)1e9 + 7;

int f[N * 2 + 1];

int F(int n) {
    if(n <= 1)
        return 1;
    if(f[n])
        return f[n];
    return f[n] = n * F(n - 1) % mod;
}

int b_pow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1)
            res *= a, res %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return res;
}

int modInverse(int a) {
    return b_pow(a % mod, mod - 2);
}

int C(int n, int k) {
    return F(n) * modInverse(F(n - k) * F(k)) % mod;
}
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
}