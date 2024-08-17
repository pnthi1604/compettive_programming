#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    int first_bit_1 = 0, last_bit_1 = n - 1;
    while(first_bit_1 < n && s[first_bit_1] != '1') first_bit_1++;
    while(last_bit_1 >= 0 && s[last_bit_1] != '1') last_bit_1--;
    // Tìm các đoạn l, r chỉ gồm các bit 0, l và r thuộc đoạn [first_bit_1, last_bit_1]
    vector<pair<int,int>> a;
    int l = first_bit_1 + 1;
    while(l < n && s[l] != '0') l++;
    int r = l + 1;
    while(l <= r && r < last_bit_1) {
        if (s[r] != '0') {
            if (s[l] == '0')
                a.push_back({l, r - 1});
            r++;
            l = r;
        } else {
            r++;
        }
    }
    if (l < n && s[l] == '0')
        a.push_back({l, r - 1});
    sort(a.begin(), a.end(), [](pair<int,int> x, pair<int,int> y) -> bool {
        return x.second - x.first < y.second - y.first;
    });
    for (pair<int,int> x : a) {
        if (k >= x.second - x.first + 1) {
            k -= x.second - x.first + 1;
            for (int i = x.first; i <= x.second; i++)
                s[i] = '1';
        }
    }
    int ans = s[0] == '1';
    int cnt_bit_0 = s[0] == '0';
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            cnt_bit_0++;
            continue;
        }
        ans++;
        if (s[i - 1] == '1')
            ans++;
    }
    if (cnt_bit_0 == n)
        cout << max(2 * k - 1, 0);
    else
        cout << ans +  min(k, cnt_bit_0) * 2;
    return 0;
}