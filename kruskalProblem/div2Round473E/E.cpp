#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int INF = (int)1e9;

map<ll,ll> dp;

ll dq(ll n) {
    if(n == 1)
        return 0;
    if(dp.find(n) != dp.end()) return dp[n];
    int j = 1;
    while((1ll << j) < n) j++;
    j--;
    return dp[n] = dq(1ll << j) + (1ll << j) + dq(n - (1ll << j));
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    cout << dq(n);
    return 0;
}