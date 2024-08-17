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
        cin >> n >> k;
        vector<int> a(n);
        for(int &x : a)
            cin >> x;
        string ans = "NO";
        int cnt_an = 0;
        for (int x : a)
            cnt_an += x == a[n - 1];
        if (a[0] == a[n - 1]) {
            if (cnt_an >= k) 
                ans = "YES";
        } else {
            if (cnt_an >= k) {
                int cnt_a0 = 0;
                int need_cnt_an = k;
                for(int j = n - 1; j >= 0; j--) {
                    need_cnt_an -= a[j] == a[n - 1];
                    //need_cnt_an <= 0: Bên phải mảng đã duyệt qua được k phần tử bằng a_n rồi
                    if (a[j] == a[0] && need_cnt_an <= 0) 
                        cnt_a0++;
                }
                if(cnt_a0 >= k)
                    ans = "YES";
            }
        }
        cout << ans << endl;
    }
    return 0;
}