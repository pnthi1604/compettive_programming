#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define hi cerr << "HIHIHI" << endl;

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        ll y = sqrt(x);
        if(y * y == x) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
