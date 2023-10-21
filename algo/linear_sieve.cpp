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
const int N = (int)1e7;
vt pr, lp(N + 1, 0);

void linearSieve(int &n) {
    for(int i = 2; i <= n; i++) {
        if(lp[i] == 0)
            lp[i] = i, pr.push_back(i);
        for(int j = 0; i * pr[j] <= n && j < pr.size(); j++)
            lp[i * pr[j]] = pr[j];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n = 100;
    linearSieve(n);
    for(int i = 1; i <= n; i++) {
        cout << "p[" << i << "] = " << lp[i] << endl;
    }
}
