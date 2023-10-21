#include <bits/stdc++.h>
#define int long long
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define ii pair<int,int>
#define vii vector<ii>
#define endl '\n'
#define _sort(a) sort(a.begin(), a.end())
#define bsUp(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
#define bsLow(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define rev(a) reverse(a.begin(), a.end())
#define all(a) a.begin(), a.end()
#define inf (int)1e18
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vt a(n);
    for(int &x : a)
        cin >> x;
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        while(dq.size() && a[dq.back()] <= a[i])
            dq.pop_back();
        dq.push_back(i);
        if(dq.front() + k < i)
            dq.pop_front();
        if(i >= k - 1)
            cout << a[dq.front()] << ' ';
    }
}
