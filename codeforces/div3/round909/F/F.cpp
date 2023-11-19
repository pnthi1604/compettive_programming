#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        for(int i = 1; i < n; i++) {
            cout << i << ' ' << i + 1 << '\n';
        }
        int cur = n - 1;
        for(int i = 0; i < q; i++) {
            int x;
            cin >> x;
            if(cur == x) {
                cout << "-1 -1 -1\n"; 
            } else {
                cout << n << ' ' << cur << ' ' << x << '\n';
                cur = x;
            }
        }
    }
    return 0;
}