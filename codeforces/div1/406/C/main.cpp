#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)1e5 + 10;
int n, tl, tr;
int a[N], id[N];

struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}

Vertex* update(Vertex* v, int tl, int tr, int pos) {
    if (tl == tr)
        return new Vertex(v->sum+1);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos));
}

int find_kth(Vertex* vl, Vertex *vr, int tl, int tr, int k) {
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2, left_count = vr->l->sum - vl->l->sum;
    if (left_count >= k)
        return find_kth(vl->l, vr->l, tl, tm, k);
    return find_kth(vl->r, vr->r, tm+1, tr, k-left_count);
}

int bs(vector<Vertex*> &roots, int l, int r, int val, int k) {
	int res = l, _l = l;
	cerr << "l = " << l << "; r = " << r << "; val = " << val << endl;
	while(l <= r) {
		int m = (l + r) / 2;
		int fk = find_kth(roots[_l], roots[m], tl, tr, k);
		cerr << "_l = " << _l << "; m = " << r << "; fk = " << fk << endl;
		if(fk >= val) {
			res = m - 1;
			l = m + 1;
		} else r = m - 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) 
		id[i] = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[i] = id[x];
		id[x] = i;
	}
	tl = 0, tr = n + 1;
	vector<Vertex*> roots;
	roots.push_back(build(tl, tr));
	for(int i = 1; i <= n; i++)
		roots.push_back(update(roots.back(), tl, tr, id[i]));
	for(int k = 0; k < n; k++) {
		int ans = 0;
		int id;
		int l = 1;
		cerr << "k = " << k << endl;
		while(l < n) {
			++ans;
			l = bs(roots, l, n - 1, l, k + 1) + 1;
			cerr << "l = " << l << endl;
		}
		cout << ans << ' ';
	}
	return 0;
}