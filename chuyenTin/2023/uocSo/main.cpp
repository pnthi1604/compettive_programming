#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll f[51];
    for(int i = 0; i <= 1; i++) f[i] = i;
    for(int i = 2; i <= 50; i++) f[i] = f[i - 1] + f[i - 2];
    int a, b, M;
    cin >> a >> b >> M;
    cout << __gcd(f[a], f[b]) % M;
    return 0;
}