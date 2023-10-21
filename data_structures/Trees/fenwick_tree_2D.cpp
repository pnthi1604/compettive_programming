#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct fwt_2d {
    vtt bit;
    int n, m;

    void init(int _n, int _m) {
        n = _n;
        m = _m;
        bit.assign(n + 1, vt(m + 1, 0));
    }

    void update(int x, int y, int val) {
        for(int i = x + 1; i <= n; i += i & -i)
            for(int j = y + 1; j <= m; j += j & -j)
                bit[i][j] += val;
    }

    int get(int x, int y) {
        int res = 0;
        for(int i = x + 1; i >= 1; i -= i & -i)
            for(int j = y + 1; j >= 1; j -= j & -j)
                res += bit[i][j];
        return res;
    }

    int get(int x1, int y1, int x2, int y2) {
        if(x1 == 0 && y1 == 0)
            return get(x2, y2);
        else if(x1 == 0) 
            return get(x2, y2) - get(x2, y1 - 1);
        else if(y1 == 0)
            return get(x2, y2) - get(x1 - 1, y2);
        else
            return get(x2, y2) + get(x1 - 1, y1 - 1) - get(x2, y1 - 1) - get(x1 - 1, y2);
    }
};

signed main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// ios::sync_with_stdio(false); cin.tie(0);
	int s, w;
	cin >> s >> w;
	vector<vector<int>> a(w, vector<int>(w, s));
	fenwick_2d ft2d(a);
	int t = 1;
	while(t != 3) {
		cin >> t;
		if(t == 1) {
			int x, y, v;
			cin >> x >> y >> v;
			x--;y--;
			ft2d.update(x, y, v);
		} else if(t == 2) {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1--;x2--;y1--;y2--;
			if(x1 < 1 && y1 < 1)
				cout << ft2d.sum(x2, y2) << endl;
			else {
				if(x1 < 1) 
					cout << ft2d.sum(x2, y2) - ft2d.sum(x2, y1 - 1) << endl;
				else if(y1 < 1)
					cout << ft2d.sum(x2, y2) - ft2d.sum(x1 - 1, y2) << endl;
				else
					cout << ft2d.sum(x2, y2) + ft2d.sum(x1 - 1, y1 - 1) - ft2d.sum(x2, y1 - 1) - ft2d.sum(x1 - 1, y2) << endl;
			}
		} else break;
	}
	return 0;
}
