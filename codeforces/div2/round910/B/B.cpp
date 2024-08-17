// CODE BY THI PHAM NegativeZero TEAM 

#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'
#define int long long

const int INF = (int)1e9;
// const ll INF = (ll)1e18;

using namespace std;

int d(int a, int b) {
    if(a % b == 0) {
        return a / b;
    }
    return a / b + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) {
        cin >> x;
    }
    int top = a.back();
    int cnt = 0;
    for(int i = a.size() - 2; i >= 0; i--) {
        if(top == 1) {
            for(int j = 0; j <= i; j++) {
                cnt += a[j] - 1;
            }
            break;
        }
        if(a[i] <= top) {
            top = a[i];
        } else {
            int x = d(a[i], top);
            cnt += x - 1;
            top = a[i] / x;
        }
    }
    cout << cnt << endl;
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