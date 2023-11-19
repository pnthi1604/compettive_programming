#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int INF = (int)1e9;

pair<int,int> find(vector<int> &a, int i) {
    int mx = -INF, mxCur = 0;
    for(i; i < a.size() - 1; i++) {
        mxCur += a[i];
        if(mxCur < 0) {
            mxCur = 0;
        } else {
            mx = max(mx, mxCur);
        }
        if(abs(a[i]) % 2 == abs(a[i + 1]) % 2) {
            return {mx, i};
        }
    }
    mx = max(mx, mxCur + a.back());
    return {mx, a.size() - 1};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = -INF;
    for(int &x : a) {
        cin >> x;
        ans = max(ans, x);
    }
    for(int i = 0; i < n; i++) {
        auto[maxVal, index] = find(a, i);
        ans = max(ans, maxVal);
        i = index;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}