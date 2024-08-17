#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main() {
    int n, k, h;
    cin >> n >> k >> h;
    h--;
    vector<int> a(n);
    for(int &x : a) 
        cin >> x;
    sort(a.begin(), a.end());

    int l = 0, r = n - 1, res = h, _sum = 0;
    while(l <= r) {
        int m = (l + r) / 2;
        ll sum = 0;
        for (int j = h; j <= m; j++)
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
    cout << a[res] + k / (res - h + 1);
    return 0;
}