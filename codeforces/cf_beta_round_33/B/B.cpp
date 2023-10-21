#include <bits/stdc++.h>
#define ll long long
#define infInt (int)1e9 + 1
// #define infLL 0x3f3f3f3f3f3f
#define infLL (int)1e17
#define endl '\n'
#define all(a) a.begin(), a.end()
#define _sort(a) sort(all(a))
#define bsUp(a, x) upper_bound(all(a), x) - a.begin()
#define bsLow(a, x) lower_bound(all(a), x) - a.begin()
#define rev(a) reverse(all(a))
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define int ll
#define hi cout << "hi\n";
using namespace std;

vector<pair<int,int>> adj[26];

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    vector<vector<int>> dist(26, vector<int>(26, infLL));
    for(int i = 0; i < n; i++) {
        char x, y;
        int w;
        cin >> x >> y >> w;
        int u = x - 'a', v = y - 'a';
        dist[u][v] = min(dist[u][v], w);
    }
    for(int i = 0; i < 26; i++)
        dist[i][i] = 0;
    if(t.length() != s.length()) {
        cout << -1;
        return 0;
    }
    for(int k = 0; k < 26; k++) {
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int res = 0;
    string ans = "";
    for(int i = 0; i < s.length(); i++) {
        int u = s[i] - 'a', v = t[i] - 'a';
        if(u == v) {
            ans += s[i];
            continue;
        }
        int mincost = infLL, resChar;
        for(char x = 'a'; x <= 'z'; x++) {
            int c = x - 'a';
            int cost1 = dist[u][c], cost2 = dist[v][c];
            if(cost1 == infLL || cost2 == infLL)
                continue;
            if(mincost > cost1 + cost2) {
                mincost = cost2 + cost1;
                resChar = x;
            }
        }
        if(mincost == infLL) {
            res = -1;
            break;
        } else {
            res += mincost;
            ans += resChar;
        }
    }
    if(res == -1)
        cout << -1;
    else
        cout << res << "\n" << ans;
}
