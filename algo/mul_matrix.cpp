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
// #define in(a); ; 
// #define hi ;
// #include "/home/phamngocthi/cp/see.cpp"
using namespace std;
const int mod = (int)1e9 + 7;

struct MaTrix {
    int row, col;
    vtt m;

    void init(int _row, int _col) {
        row = _row;
        col = _col;
        m.assign(row, vt(col));
    }

    MaTrix operator * (MaTrix &o) {
        MaTrix res;
        res.init(row, o.col);
        for(int i = 0; i < row; i++) 
            for(int j = 0; j < o.col; j++)
                for(int k = 0; k < col; k++)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * o.m[k][j]) % mod;
        return res;
    }

    MaTrix bp(int n) {
        MaTrix base = *this, res;
        res.init(row, row);
        for(int i = 0; i < row; i++)
            res.m[i][i] = 1;
        while(n) {
            if(n & 1)
                res = res * base;
            base = base * base;
            n >>= 1;
        }
        return res;
    }
};

struct MulMaTrix {
    MaTrix bs, init;

    MulMaTrix(int n, int p, int m) {
        bs.init(n, p);
        init.init(p, m);
        bs.m = {{1, 1}, {1, 0}};
        init.m = {{1}, {0}};
    }

    int getAns(int n) {
        if(n <= 1)
            return n;
        MaTrix res = bs.bp(n - 1) * init;
        return res.m[0][0] % mod;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    MulMaTrix mt(2, 2, 1);
    cout << mt.getAns(n);
}
