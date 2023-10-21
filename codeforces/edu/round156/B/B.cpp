#include <bits/stdc++.h>
#define int long long
#define dll double

using namespace std;

const dll unit = 1e-6;
bool compare(dll a, dll b) {
	return a < b || (abs(a - b) < unit);
}

struct Point {
	dll x, y;

	void init(dll _x, dll _y) {
		x = _x;
		y = _y;
	}

	dll dist(Point o) {
		auto[xo, yo] = o;
		return sqrt(pow(xo - x, 2) + pow(yo - y, 2));
	}
};

struct Circle {
	dll r;
	Point O;

	void init(Point a, dll _r) {
		O = a;
		r = _r;
	}

	bool in(Point a) {
		return compare(O.dist(a), r);
	}
};

bool check(Circle Ca, Circle Cb, Point P, dll r, dll dab) {
	Point O;
	O.init(0, 0);
	if(Ca.in(O) && Ca.in(P))
		return true;
	if(Cb.in(O) && Cb.in(P))
		return true;
	if(((Ca.in(O) && Cb.in(P)) || (Cb.in(O) && Ca.in(P))) && compare(dab, 2 * r))
		return true;
	return false;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		Point P, A, B;
		dll px, py, ax, ay, bx, by;
		cin >> px >> py >> ax >> ay >> bx >> by;
		P.init(px, py);
		A.init(ax, ay);
		B.init(bx, by);
		Circle Ca, Cb;
		dll dab = A.dist(B);
		dll l = 0.0, r = 1e4;
		dll ans = 1e4;
		while(compare(l, r)) {
			dll m = (l + r) / 2;
			Ca.init(A, m);
			Cb.init(B, m);
			if(check(Ca, Cb, P, m, dab)) {
				ans = m;
				r = m - unit;
			} else {
				l = m + unit;
			}
		}
		cout << setprecision(6) << fixed << ans << '\n';
	}
}