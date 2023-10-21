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

struct Point {
    int x, y;

    void init(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

struct Circle {
    int r;
    Point O;

    void init(int _r, int x, int y) {
        r = _r;
        O.init(x, y);
    }

    bool in(Point a) {
        auto[x, y] = a;
        auto[u, v] = O;
        return (x - u) * (x - u) + (y - v) * (y - v) <= r * r;
    }
};

const int nmax = 1001, mmax = 1001, kmax = (int)1e5 + 1;

bitset<mmax> inFen[nmax];

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<Point> ctrls(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        Point p;
        p.init(x, y);
        ctrls[i] = p;
    }
    vector<Circle> fens(m);
    for(int i = 0; i < m; i++) {
        int r, x, y;
        cin >> r >> x >> y;
        Circle c;
        c.init(r, x, y);
        fens[i] = c;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(fens[j].in(ctrls[i])) {
                inFen[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << inFen[a].count() + inFen[b].count() - 2 * (inFen[a] & inFen[b]).count() << endl;
    }
}
