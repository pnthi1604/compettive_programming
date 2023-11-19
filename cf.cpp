#include <bits/stdc++.h>
#define ll long long
#define int long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'
using namespace std;

ll sum(vector<int> &a) {
    ll ans = 0;
    for(int i = 0; i < a.size(); i++) {
        ans += a[i];
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << sum(a) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
