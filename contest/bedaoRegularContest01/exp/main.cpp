#include <bits/stdc++.h>
#define int long long

using namespace std;

int bpow(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) {
			res *= a;
		}
		a *= a;
		b >>= 1;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int ax, bx, ay, by;
		cin >> ax >> bx >> ay >> by;
		if(bx >= by) {
			int p = bx - by;
			if(bpow(10, p) > ay / ax) {
				cout << "X > Y";
			} else {
				if(ax % ay == 0 && ax / ay == bpow(10, p)) {
					cout << "X = Y";
				} else {
					cout << "X < Y";
				}
			}
		} else {
			int p = by - bx;
			if(bpow(10, p) > ax / ay) {
				cout << "X < Y";
			} else {
				cout << "X > Y";
			}
		}
		cout << "\n";
	}
}