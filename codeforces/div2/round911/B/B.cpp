#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ok1 = 0, ok2 = 0, ok3 = 0;
    if(b - a >= 0 && (b - a) % 3 == 0 && (b - a) / 3 <= c) {
        ok3 = 1;
    }
    if(c - a >= 0 && (c - a) % 3 == 0 && (c - a) / 3 <= b) {
        ok2 = 1;
    }
    if(a - b >= 0 && (a - b) % 3 == 0 && (a - b) / 3 <= c) {
        ok3 = 1;
    }
    if(c - b >= 0 && (c - b) % 3 == 0 && (c - b) / 3 <= a) {
        ok1 = 1;
    }
    if(a - c >= 0 && (a - c) % 3 == 0 && (a - c) / 3 <= b) {
        ok2 = 1;
    }
    if(b - c >= 0 && (b - c) % 3 == 0 && (b - c) / 3 <= a) {
        ok1 = 1;
    }
    cout << ok1 << ' ' << ok2 << ' ' << ok3 << '\n';
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();        
    }
}