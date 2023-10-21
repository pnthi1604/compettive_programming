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
#define hi ;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> minVal(m, infLL);
    for(int i = 0; i < n; i++) {
        int row, val;
        cin >> row >> val;
        row--;
        minVal[row] = min(minVal[row], val);
    }
    int sumVal = 0;
    for(int i = 0; i < m; i++)
        sumVal += minVal[i];
    cout << min(sumVal, k);
}
