#include <bits/stdc++.h>
#define ll long long
#define infInt (int)1e9 + 1
// #define infLL 0x3f3f3f3f3f3f
#define infLL (int)1e17
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define vtttt vector<vttt>
#define pii pair<int, int>
#define vpii vector<pii>
#define endl '\n'
#define all(a) a.begin(), a.end()
#define _sort(a) sort(all(a))
#define bsUp(a, x) upper_bound(all(a), x) - a.begin()
#define bsLow(a, x) lower_bound(all(a), x) - a.begin()
#define rev(a) reverse(all(a))
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define int ll
#define hi ;
using namespace std;

void count(string s, vector<int> &cnt) {
    for(char x : s)
        cnt[x - 'a']++;
}

signed main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s, t, ss = "";
    cin >> s >> t;
    int ns = s.length(), nt = t.length();
    vector<int> cntT(26, 0), cntS(26, 0);
    count(s, cntS);
    count(t, cntT);
    bool ok = true;
    for(char x : t) {
        if(cntS[x - 'a'] < cntT[x - 'a']) {
            ok = false;
        }
    }
    if(ok == false) {
        cout << -1;
        return 0;
    }
    for(char x = 'a'; x <= 'z'; x++)
        cntS[x - 'a'] -= cntT[x - 'a'];
    for(char x : s) {
        if(cntT[x - 'a'])
            ss += x;
    }
    string res = "";
    cout << "ss = " << ss << endl;
    for(int i = 0; i < ss.length(); i++) {
        cout << ss[i] << " va cnt = " << cntS[ss[i] - 'a'] << endl;
        if(cntS[ss[i] - 'a'] == 0) {
            res += ss[i];
            cout << "res = " << res << endl;
            continue;
        }
        int j = i;
        cout << "ss[i] = " << ss[i] << endl; 
        while(j + 1 < ss.length() && cntS[s[j + 1] - 'a'] != 0 && s[j + 1] > s[j])
            j++;
        cout << "i = " << i << "; j = " << j << endl;
        for(int k = i; k <= j; k++)
            cntS[ss[k] - 'a']--;
        i = j;
    }
}
