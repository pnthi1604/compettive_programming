#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = (int)5e6;

int divR(int a, int b) {
    if(a % b == 0)
        return a / b;
    return a / b + 1;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(); cout.tie(0);
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    int ans = 0;
    for(int x = a; x <= b; x++) {
        int g = gcd(x, m);
        int mm = m / g;
        ans += max(0LL, d / mm - divR(c, mm) + 1);
    }
    cout << ans;
}