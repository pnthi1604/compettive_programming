#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    int ans = 0;
    for(i; i < n - 1; i++) {
        if(s[i] == '#') 
            continue;
        int j = i + 1;
        for(j; j < n; j++) {
            if(s[j] == s[j - 1] && s[j] == '.') {
                continue;
            } else {
                break;
            }
        }
        if(j - i >= 3) {
            ans = 2;
            break;
        }
        i = j - 1;
    }
    if(ans == 0) {
        for(int i = 0; i < n; i++) {
            ans += s[i] == '.';
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}