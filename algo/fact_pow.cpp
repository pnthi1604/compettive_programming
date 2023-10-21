#include <bits/stdc++.h>
#define int long long
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
using namespace std;

int factPow(int n, int k) {
    int res = 0;
    while(n) {
        n /= k;
        res += n;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, p; cin >> n >> p;
    cout << factPow(n, p);
}
