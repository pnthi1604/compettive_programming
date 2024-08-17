#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for(string &x : s)
        cin >> x;
    
    pair<int,int> A, B;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (s[i][j] == 'A')
                A = {i, j};
            else if (s[i][j] == 'B')
                B = {i, j};
        }
    }

    auto bfs = [&]() -> string {
        int dx[4] = { 0, 0, 1, -1};
        int dy[4] = { -1, 1, 0, 0};
        string move = "LRDU";

        vector<vector<pair<int,int>>> par(n, vector<pair<int,int>>(m, {-1, -1}));
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        queue<pair<int,int>> q;
        q.push(A);
        vis[A.first][A.second] = true;
        while(q.size()) {
            pair<int,int> top = q.front();
            q.pop();         
            for(int i = 0; i < move.length(); i++) {
                int x = top.first + dx[i];
                int y = top.second + dy[i];
                if (x < 0 || y < 0 || x >= n || y >= m || s[x][y] == '#' || vis[x][y])
                    continue;

                if (make_pair(x, y) == B) {
                    par[x][y] = top;
                    string res = "";
                    pair<int,int> cur = B;
                    while(cur != A) {
                        pair<int,int> par_cur = par[cur.first][cur.second];
                        for (int i = 0; i < move.length(); i++) {
                            int x = cur.first - dx[i];
                            int y = cur.second - dy[i];
                            if (x < 0 || y < 0 || x >= n || y >= m)
                                continue;
                            if (make_pair(x, y) == par_cur) {
                                res += move[i];
                                break;
                            }
                        }
                        cur = par_cur;
                    }
                    return res;
                }       

                par[x][y] = top;
                q.push({x, y});
                vis[x][y] = true;
            }
        }
        return "NO";
    };

    string res = bfs();
    if (res == "NO")
        cout << "NO\n";
    else {
        cout << "YES\n";
        cout << res.length() << endl;
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    return 0;
}