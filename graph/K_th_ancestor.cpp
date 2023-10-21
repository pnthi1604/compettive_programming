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
// #define in(a); ; 
// #define hi ;
// #include "/home/phamngocthi/cp/see.cpp"
using namespace std;

const lgmax = 20;
const int N = (int)2e5;
int far[lgmax + 1][N + 1];

int findK_th_ancestor(int x, int k) {
    for(int h = lgmax; h >= 0; h--) 
        if((1 << h) <= k) {
            x = far[h][x];
            k -= (1 << h);
        }
    return x;
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> far[0][i];
    for(int h = 1; h <= lgmax; h++) {
        for(int i = 0; i < n; i++) {
            far[h][i] = far[h - 1][far[h - 1][i]];
        }
    }
}
//BI BUG LA DO TRAN SO HOAC LA MOD BI AM DO :V, COI LAI DUM!