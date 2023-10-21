#include <bits/stdc++.h>
#define ll long long
#define infInt (int)1e9 + 1
// #define infLL 0x3f3f3f3f3f3f
#define infLL (int)1e17
#define endl '\n'
#define all(a) a.begin(), a.end()
#define _sort(a) sort(all(a))
#define bsUp(a, x) upper_bound(all(a), x) - a.begin()
#define bsLow(a, x) lower_bound(all(a), x) - a.begin()
#define rev(a) reverse(all(a))
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define int ll
#define hi ;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n + 1), sum(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int res = sum[n];
    int minVal = 0;
    for(int i = 1; i <= n; i++) {
        minVal = min(minVal, sum[i]);
        res = max(res, -sum[n] + 2 * sum[i] - 2 * minVal);
    }
    cout << res;
}
