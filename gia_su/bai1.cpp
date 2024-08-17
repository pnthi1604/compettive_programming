#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int query;
    cin >> query;
    vector<int> a(1, 0);
    for (char c : s)
        a.push_back(c - '0');

    int n = a.size() - 1;
    vector<int> sum(n + 1, 0), sum_odd(n + 1, 0), sum_even(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        sum_odd[i] = sum_odd[i - 1] + (i % 2 == 1 ? a[i] : 0);
        sum_even[i] = sum_even[i - 1] + (i % 2 == 0 ? a[i] : 0);
    }

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(11, vector<ll>(3, 0)));
    vector<vector<vector<ll>>> max_num(n + 1, vector<vector<ll>>(11, vector<ll>(3, 0)));
    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        int x = sum[i];
        int y = sum_odd[i];
        int z = sum_even[i];
        int r = abs(y - z) % 11;
        for (int j = 0; j < 11; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][(j + r) % 11][(x + k) % 3] = dp[i - 1][j][k];
                max_num[i][(j + r) % 11][(x + k) % 3] = max_num[i - 1][j][k] * 10 + a[i];   
            }
        }
        dp[i][r][x % 3] += 1;
        max_num[i][r][x % 3] = max(max_num[i][r][x % 3], (ll)a[i]);
    }

    ll ans = 0;
    if (query == 1) {
        for (int i = 1; i <= n; i++) {
            ans += dp[i][0][0];
        }
        cout << ans;
    } else {
        for(int i = 1; i <= n; i++) {
            ans = max(ans, max_num[i][0][0]);
        }
        if (ans == 0) {
            for (int x : a) {
                if (x == 0) {
                    cout << ans;
                    return 0;
                }
            }
            cout << -1;
        } else {
            cout << ans;
        }
    }
    return 0;
}