#include <bits/stdc++.h>
#define ll long long
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define pii pair<int,int>
#define vpii vector<pii>
#define endl '\n'
#define inf (int)1e9
#define infLL (ll)1e18
#define _sort(a) sort(a.begin(), a.end())
#define bsUp(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
#define bsLow(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define rev(a) reverse(a.begin(), a.end())
#define all(a) a.begin(), a.end()
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define int ll
// #include "/home/phamngocthi/cp/see.cpp"
using namespace std;

struct line {
    int a, b;

    int get(int x) {
        return a * x + b;
    }

    bool canRemoveL1(line l1, line l2) {
        return (b - l2.b) * (l2.a - l1.a) <= (l1.b - l2.b) * (l2.a - a);
    }
};

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vt s(n + 1), f(n + 1);
    cin >> f[0];
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    for(int i = 1; i <= n; i++)
        cin >> f[i];
    vt dp(n + 1);
    dp[0] = 0;
    vector<line> lines;
    for(int i = 1; i <= n; i++) {
        line new_line = {f[i - 1], dp[i - 1]};
        while(lines.size() >= 2 && new_line.canRemoveL1(lines[lines.size() - 1], lines[lines.size() - 2])) 
            lines.pop_back();
        lines.push_back(new_line);
        int l = 0, r = lines.size() - 2, res = 0;
        while(l <= r) {
            int m = (l + r) / 2;
            if(lines[m].get(s[i]) > lines[m + 1].get(s[i]))
                res = m + 1, l = m + 1;
            else r = m - 1;
        }
        dp[i] = lines[res].get(s[i]);
        l = 0, r = lines.size() - 2, res = 0;
        while(l <= r) {
            int m = (l + r) / 2;
            if(lines[m].get(s[i]) < lines[m + 1].get(s[i]))
                res = m, r = m - 1;
            else l = m + 1;
        }
        dp[i] = min(dp[i], lines[res].get(s[i]));
    }
    cout << dp[n];
}  

