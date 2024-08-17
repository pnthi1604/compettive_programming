#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define hi cerr << "HIHIHI" << endl;

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string t, p;
    cin >> t >> p;
    auto solve = [&](string s) -> vector<vector<int>> {
        vector<vector<int>> idx(s.length(), vector<int>());
        map<int, vector<int>> id;
        for(int i = 0; i < s.length(); i++) {
            id[s[i]].push_back(i);
        }
        for(int i = 0; i < s.length(); i++) {
            if(id.find(s[i]) == id.end()) continue;
            idx[i] = id[s[i]];
            id.erase(s[i]);
        }
        return idx;
    };
            
    auto check = [&](string a, string b) -> bool {
        vector<vector<int>> resa = solve(a);
        vector<vector<int>> resb = solve(b);
        return resa == resb;
    };
    vector<int> ans;
    for(int i = 0; i + p.length() - 1 < t.length(); i++) {
        string tt = t.substr(i, p.length());
        if(check(tt, p)) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
    for(int x : ans)
        cout << x << ' ';
    return 0;
}
