// CODE BY THI PHAM NegativeZero TEAM 

#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";

const int INF = (int)1e9;
// const ll INF = (ll)1e18;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char,int> cnt;
    for(int i = 0; i < s.length(); i++) {
        cnt[s[i]]++;
    }
    char B = 'B', A = 'A';
    if(cnt[B] == k) {
        cout << 0;
    } else if(cnt[B] < k) {
        int cntB = cnt[B];
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == A) {
                cntB++;
            }
            if(cntB == k) {
                cout << 1 << '\n' << i + 1 << " B";
                break;
            }
        }
    } else {
        int cntB = cnt[B];
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == B) {
                cntB--;
            }
            if(cntB == k) {
                cout << 1 << '\n' << i + 1 << " A";
                break;
            }
        }
    }
    cout << '\n';
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