#include <bits/stdc++.h>
#define int long long
#define inf (int)1e18
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

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vt a(n), b;
    for(int &x : a)
        cin >> x;
    b.push_back(a[0]);
    for(int i = 1; i < a.size(); i++) {
        int it = bsLow(b, a[i]);
        if(it >= b.size())
            b.push_back(a[i]);
        else b[it] = a[i];
    }
    cout << b.size();
}