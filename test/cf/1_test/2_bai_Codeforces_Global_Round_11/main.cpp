#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        char w = 'W', l = 'L';
        int first_w = 0, last_w = n - 1;
        while(first_w < n && s[first_w] != w) first_w++;
        while(last_w >= 0 && s[last_w] != w) last_w--;
        // Tìm các đoạn l, r chỉ gồm các bit 0, l và r thuộc đoạn [first_w, last_w]
        vector<pair<int,int>> a;
        int l_l = first_w + 1;
        while(l_l < n && s[l_l] != l) l_l++;
        int r_l = l_l + 1;
        while(l_l <= r_l && r_l < last_w) {
            if (s[r_l] != l) {
                if (s[l_l] == l)
                    a.push_back({l_l, r_l - 1});
                r_l++;
                l_l = r_l;
            } else {
                r_l++;
            }
        }
        if (l_l < n && s[l_l] == l)
            a.push_back({l_l, r_l - 1});
        sort(a.begin(), a.end(), [](pair<int,int> x, pair<int,int> y) -> bool {
            return x.second - x.first < y.second - y.first;
        });
        bool flag = false;
        for (pair<int,int> x : a) {
            if (k >= x.second - x.first + 1) {
                k -= x.second - x.first + 1;
                for (int i = x.first; i <= x.second; i++)
                    s[i] = w;
            }
        }
        int ans = s[0] == w;
        int cnt_l = s[0] == l;
        for (int i = 1; i < n; i++) {
            if (s[i] == l) {
                cnt_l++;
                continue;
            }
            ans++;
            if (s[i - 1] == w)
                ans++;
        }
        if (cnt_l == n)
            cout << max(2 * k - 1, 0) << endl;
        else
            cout << ans +  min(k, cnt_l) * 2 << endl;
    }
    return 0;
}