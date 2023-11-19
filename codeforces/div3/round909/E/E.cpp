#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = (int)1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int x = INF, id = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(x > a[i]) {
                x = a[i];
                id = i;
            }
        }
        bool ok = true;
        for(int j = id + 1; j < n; j++) {
            if(a[j] < a[j - 1]) {
                ok = false;
            }
        }
        if(ok == false) {
            cout << "-1\n";
        } else {
            cout << id << '\n';
        }
    }
    return 0;
}