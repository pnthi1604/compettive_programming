#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'
#define int ll

using namespace std;

const int INF = (int)1e9;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    int max_x = 0, min_y = m + 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) {
                if(j == 1) {
                    max_x = n, min_y = 1;
                }
                if(i > max_x) {
                    max_x = i, min_y = j;
                } else if(i == max_x) {
                    min_y = min(min_y, j);
                }
                a[i][j] = 100;
            }
        }
    vector<vector<int>> dp1(n + 1, vector<int>(m + 1, INF));
    vector<vector<int>> dp2(n + 1, vector<int>(m + 1, INF));
    int cnt2 = 0, cnt5 = 0;
    int tmp = a[1][1];
    while(tmp >= 2 && (tmp % 2 == 0 || tmp % 5 == 0)) {
        if(tmp % 2 == 0) tmp /= 2, cnt2++;
        if(tmp % 5 == 0) tmp /= 5, cnt5++;
    }
    dp1[1][1] = cnt2;
    dp2[1][1] = cnt5;
    int dx[2] = {1, 0}; 
    int dy[2] = {0, 1};
    //D, L
    char d[2] = {'D', 'L'};
    pair<int,int> par1[n + 1][m + 1];
    pair<int,int> par2[n + 1][m + 1];
    char c1[n + 1][m + 1];
    char c2[n + 1][m + 1];
    auto check1 = [&](int i, int j, int ii, int jj) -> bool {
        int tmp = a[i][j];
        int cnt2 = 0;
        while(tmp % 2 == 0) 
            tmp /= 2, cnt2++;
        if(dp1[ii][jj] + cnt2 < dp1[i][j]) {
            dp1[i][j] = dp1[ii][jj] + cnt2;
            return true;
        } else {
            return false;
        }
    };
    auto check2 = [&](int i, int j, int ii, int jj) -> bool {
        int tmp = a[i][j];
        int cnt5 = 0;
        while(tmp % 5 == 0) 
            tmp /= 5, cnt5++;
        if(dp2[ii][jj] + cnt5 < dp2[i][j]) {
            dp2[i][j] = dp2[ii][jj] + cnt5;
            return true;
        } else {
            return false;
        }
    };
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 1 && j == 1) continue;
            for(int t = 2; t >= 0; t--) {
                int ii = -dx[t] + i;
                int jj = -dy[t] + j;
                if(ii >= 1 && ii <= n && jj >= 1 && jj <= m) {
                    if(check1(i, j, ii, jj)) {
                        par1[i][j] = {ii, jj};
                        c1[i][j] = d[t];
                    }
                    if(check2(i, j, ii, jj)) {
                        par2[i][j] = {ii, jj};
                        c2[i][j] = d[t];
                    }
                }
            }
        }
    }
    int ans = min(dp1[n][m], dp2[n][m]);
    if(ans > 1 && max_x != 0 && min_y != m + 1) {
        cout << 1 << endl;
        for(int i = 2; i <= max_x; i++) 
            cout << 'D';
        for(int i = 2; i <= min_y; i++)
            cout << 'L';
        for(int i = max_x + 1; i <= n; i++)
            cout << 'D';
        for(int i = min_y + 1; i <= m; i++)
            cout << 'L';
    } else {
        int x = n, y = m;
        string res1 = "", res2 = "";
        if(ans == dp1[n][m]) {
            while(true) {
                // cerr << "x = " << x << "; y = " << y << endl;
                res1 += c1[x][y];
                auto[xx, yy] = par1[x][y];
                x = xx;
                y = yy;
                if(x == 1 && y == 1) break;
            }
        }
        x = n, y = m;
        if(ans == dp2[n][m]) {
            while(true) {
                // cerr << "x = " << x << "; y = " << y << endl;
                res2 += c2[x][y];
                auto[xx, yy] = par2[x][y];
                x = xx;
                y = yy;
                if(x == 1 && y == 1) break;
            }            
        }
        // cerr << "res1 = " << res1 << endl;
        // cerr << "res2 = " << res2 << endl;
        reverse(res1.begin(), res1.end());
        reverse(res2.begin(), res2.end());
        string res = res1;
        if(res2.length() > res1.length() || (res2.length() == res1.length() && res2 < res1)) res = res2;
        // cerr << "res = " << res << endl;
        if(ans == 1 && max_x != 0 && min_y != m + 1) {
            string res1 = "";
            for(int i = 2; i <= max_x; i++) 
                res1 += 'D';
            for(int i = 2; i <= min_y; i++)
                res1 += 'L';
            for(int i = max_x + 1; i <= n; i++)
                res1 += 'D';
            for(int i = min_y + 1; i <= m; i++)
                res1 += 'L';
            res = min(res, res1);
        }
        cout << ans << endl;
        cout << res;
    }
    return 0;
}
