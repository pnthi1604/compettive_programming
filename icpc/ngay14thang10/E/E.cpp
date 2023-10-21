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
#define hi ;
using namespace std;

vector<vector<int>> del(vector<vector<int>> &a, int val) {
    vector<vector<int>> res = a;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            if(val > a[i][j]) {
                res[i][j] = -1;
            }
        }
    }
    return res;
}

bool check(vector<vector<int>> a) {
    //check row
    for(int j = 0; j < a.size(); j++) {
        bool ok = false;
        for(int i = 0; i < a.size(); i++) {
            if(a[i][j] != -1)
                ok = true;
        }
        if(ok == false)
            return false;
    }
    //check col
    for(int i = 0; i < a.size(); i++) {
        bool ok = false;
        for(int j = 0; j < a.size(); j++) {
            if(a[i][j] != -1)
                ok = true;
        }
        if(ok == false)
            return false;
    }
    return true;
}

signed main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> vals;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            vals.push_back(a[i][j]);
        }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cerr << a[i][j] << ' ';
        }
        cerr << '\n';
    }
    sort(all(vals), greater<int>());
    for(int x : vals)
        cerr << x << ' ';
    cerr << endl;
    int ans = 0;
    for(int x : vals) {
        cerr << "x = " << x << endl;
        vector<vector<int>> delA = del(a, x);
        cerr << "check mang delA\n";
        for(int i = 0; i < delA.size(); i++) {
            for(int j = 0; j < delA.size(); j++) {
                cerr << delA[i][j] << ' ';
            }
            cerr << '\n';
        }
        if(check(delA)) {
            ans = x;
            break;
        }
    }
    cout << ans;
}
