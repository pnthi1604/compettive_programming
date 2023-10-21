// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define infInt (int)1e9 + 1
// #define infLL 0x3f3f3f3f3f3f
// #define vt vector<int>
// #define vtt vector<vt>
// #define vttt vector<vtt>
// #define vtttt vector<vttt>
// #define pii pair<int, int>
// #define vpii vector<pii>
// #define endl '\n'
// #define _sort(a) sort(a.begin(), a.end())
// #define bsUp(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
// #define bsLow(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
// #define rev(a) reverse(a.begin(), a.end())
// #define all(a) a.begin(), a.end()
// #define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
// #define int ll
// // #include "/home/phamngocthi/cp/see.cpp"
// using namespace std;

// int N, Q;

// struct Query {
//     int id, x1, y1, x2, y2, k;
// };
// vt vals, ans;
// vtt a, b;

// struct val_matrix {
//     int i, j, val;

//     bool operator<(const val_matrix &o) const {
//         return val < o.val;
//     }
// };

// vector<val_matrix> vals_matrix;

// struct fwt_2d {
//     vtt bit;
//     int n, m;

//     void init(int _n, int _m) {
//         n = _n + 1;
//         m = _m + 1;
//         bit.assign(n + 1, vt(m + 1, 0));
//     }

//     void update(int x, int y, int val) {
//         for(int i = x + 1; i <= n; i += i & -i)
//             for(int j = y + 1; j <= m; j += j & -j)
//                 bit[i][j] += val;
//     }

//     int get(int x, int y) {
//         int res = 0;
//         for(int i = x + 1; i >= 1; i -= i & -i)
//             for(int j = y + 1; j >= 1; j -= j & -j)
//                 res += bit[i][j];
//         return res;
//     }

//     int get(int x1, int y1, int x2, int y2) {
//         if(x1 == 0 && y1 == 0)
//             return get(x2, y2);
//         else if(x1 == 0) 
//             return get(x2, y2) - get(x2, y1 - 1);
//         else if(y1 == 0)
//             return get(x2, y2) - get(x1 - 1, y2);
//         else
//             return get(x2, y2) + get(x1 - 1, y1 - 1) - get(x2, y1 - 1) - get(x1 - 1, y2);
//     }
// } ft2d;

// void pbs(int l, int r, vector<Query> &queries) {
//     if(l > r || queries.size() == 0)
//         return;

//     int m = (l + r) / 2;

//     for(int i = 0; i < vals_matrix.size(); i++) {
//         if(vals_matrix[i].val <= m) {
//             ft2d.update(vals_matrix[i].i, vals_matrix[i].j, 1);
//         } else {
//             break;
//         }
//     }

//     vector<Query> queriesL, queriesR;

//     for(int i = 0; i < queries.size(); i++) {
//         int cnt = ft2d.get(queries[i].x1, queries[i].y1, queries[i].x2, queries[i].y2);
//         if(cnt >= queries[i].k) {
//             ans[queries[i].id] = vals[m];
//             queriesL.push_back(queries[i]);
//         } else {
//             queriesR.push_back(queries[i]);
//         }
//     }

//     for(int i = 0; i < N * N; i++) {
//         if(vals_matrix[i].val <= m) {
//             ft2d.update(vals_matrix[i].i, vals_matrix[i].j, -1);
//         } else {
//             break;
//         }
//     }

//     pbs(l, m - 1, queriesL);
//     vector<Query> ().swap(queriesL);
//     pbs(m + 1, r, queriesR);
//     vector<Query> ().swap(queriesR);
// }

// signed main() {
//     ios::sync_with_stdio(false); cin.tie(0);
//     cin >> N >> Q;
//     a.resize(N, vt(N));
//     for(int i = 0; i < N; i++)
//         for(int j = 0; j < N; j++) {
//             cin >> a[i][j];
//             vals.push_back(a[i][j]);
//         }
//     _sort(vals);
//     uni(vals);
//     for(int i = 0; i < N; i++)
//         for(int j = 0; j < N; j++) {
//             vals_matrix.push_back({i, j, bsLow(vals, a[i][j])});
//         }

//     _sort(vals_matrix);
//     vector<Query> queries;
//     for(int i = 0; i < Q; i++) {
//         int x1, y1, x2, y2, k;
//         cin >> x1 >> y1 >> x2 >> y2 >> k;
//         x1--, y1--, x2--, y2--;
//         queries.push_back({i, x1, y1, x2, y2, k});
//     }

//     ft2d.init(N, N);
//     ans.assign(Q, -1);
//     pbs(0, vals.size() - 1, queries);
//     for(int i = 0; i < Q; i++)
//         cout << ans[i] << "\n";
// }














#include <bits/stdc++.h>
#define int long long
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define ii pair<int,int>
#define vii vector<ii>
#define endl '\n'
#define _sort(a) sort(a.begin(), a.end())
#define bsUp(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
#define bsLow(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define rev(a) reverse(a.begin(), a.end())
#define all(a) a.begin(), a.end()
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
using namespace std;

const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

#define mt(args...) { string _s = #args; replace(begin(_s), end(_s), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); out_error(_it, args); cout << '\n';}

void out_error(istream_iterator<string> it) {}
template<typename T, typename... Args>
void out_error(istream_iterator<string> it, T a, Args... args) {
    cerr << " [" << *it << " = " << a << "] ";
    out_error(++it, args...);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vtt a(n, vt(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    for(int i = 0; i < q; i++) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        x1--, x2--, y1--, y2--;
        vt b;
        for(int x = x1; x <= x2; x++)
            for(int y = y1; y <= y2; y++)
                b.push_back(a[x][y]);
        _sort(b);
        cout << b[k - 1] << endl;
    }
}
