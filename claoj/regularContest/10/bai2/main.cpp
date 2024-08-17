#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define hi cerr << "HIHIHI" << endl;
#define int ll

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<int,int> cnt;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for(auto x : cnt) {
        ans = max(ans, x.second);
    }
    cout << ans;
    return 0;
}