#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) 
        cin >> x;
    sort(a.begin(), a.end());

    int l = 0, r = n - 1, mid_idx = n / 2, res = mid_idx, _sum = 0;
    while(l <= r) {
        int m = (l + r) / 2;
        ll sum = 0;
        for (int j = mid_idx; j <= m; j++)
            sum += a[m] - a[j];
        if (sum <= k) {
            res = m;
            l = m + 1;
            _sum = sum;
        } else {
            r = m - 1;
        }
    }
    k -= _sum;
    cout << a[res] + k / (res - mid_idx + 1);
    return 0;
}