// CODE BY THI PHAM NegativeZero TEAM 

#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'
#define int long long

// const int INF = (int)1e9;
const ll INF = (ll)1e18;

using namespace std;

void check(set<int> a) {
    for(int x : a) {
        cerr << x << ' ';
    }
    cerr << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x : a) {
        cin >> x;
    }
    for(int &x : b) {
        cin >> x;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
    }
    int res = ans;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            ans = max(ans, res - abs(a[i] - b[i]) - abs(a[j] - b[j]) + abs(a[i] - b[j]) + abs(a[j] - b[i]));
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}