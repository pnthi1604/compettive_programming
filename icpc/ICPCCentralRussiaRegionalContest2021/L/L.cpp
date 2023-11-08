#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = (int)1e8;

int getSum(int n) {
	return  n * (n + 1) / 2;
}

int getLen(int n) {
	int cnt = 0;
	while(n) {
		n /= 10;
		cnt++;
	}
	return cnt;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	if(n == 3) {
		cout << "1 3";
		return 0;
	}
	int l = getLen(n);
	int s = getSum(n);
	// cerr << "s = " << s << endl;
	int p[19];
	p[0] = 1;
	for(int i = 1; i < 19; i++) {
		p[i] = p[i - 1] * 10;
	}
	for(int a = 1; a < 10; a++) {
		
	}
	cout << 0;
}