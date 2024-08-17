#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define hi cerr << "HIHIHI" << endl;

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 1;
    vector<int> dpr(n + 1), dpl(n + 1);
    for(int i = 1; i <= n; i++) {
        if(a[i] > a[i - 1])
            dpl[i] = dpl[i - 1] + 1;
        else
            dpl[i] = 1;
        ans = max(ans, dpl[i]);
    }
    dpr[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        dpr[i] = 1;
        if(a[i] < a[i + 1])
            dpr[i] += dpr[i + 1];
        ans = max(ans, dpr[i]);
    }
    for(int i = x + 2; i <= n; i++) {
        int j = i - x - 1;
        if(a[i] > a[j]) ans = max(ans, dpl[j] + dpr[i]);
    }
    cout << ans;
    return 0;
}