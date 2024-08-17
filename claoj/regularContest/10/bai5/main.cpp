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
            
    auto check = [&](string &a, vector<int> &id) -> bool {
        for(int i = 1; i < id.size(); i++)
            if(a[id[i]] != a[id[i - 1]]) return false;
        return true;
    };
    auto check1 = [&](string &a, vector<vector<int>> idx) -> bool {
        for(int j = 0; j < idx.size(); j++) {
            if(check(a, idx[j]) == false) return false;
        }
        return true;
    };
    map<int,int> cnt;
    map<int,int> cnt1;
    vector<int> ans;
    vector<vector<int>> idx = solve(p);
    for(int i = 0; i < p.length(); i++) {
        cnt[t[i]]++;
        cnt1[p[i]]++;
    }
    for(int i = 0; i + p.length() - 1 < t.length(); i++) {
        string tt = t.substr(i, p.length());
        if(check1(tt, idx) && cnt.size() == cnt1.size()) 
            ans.push_back(i + 1);
        cnt[t[i]]--;
        if(cnt[t[i]] == 0) cnt.erase(t[i]);
        if(i + p.length() < t.length()) cnt[t[i + p.length()]]++;
    }
    cout << ans.size() << endl;
    for(int x : ans) 
        cout << x << ' ';
    return 0;
}