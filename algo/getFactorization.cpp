#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define pii pair<int,int>
#define vpii vector<pii>
#define endl '\n'
#define _sort(a) sort(a.begin(), a.end())
#define bsUp(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
#define bsLow(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define rev(a) reverse(a.begin(), a.end())
#define all(a) a.begin(), a.end()
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define int ll
// #include "/home/phamngocthi/cp/see.cpp"
using namespace std;

const int N = (int)1e6;

int spf[N];

void sieve() {
	for(int i = 1; i <= N; i++)
		spf[i] = i;

	for(int i = 4; i <= N; i += 2)
		spf[i] = 2;

	for(int i = 3; i * i <= N; i += 2) {
		if(spf[i] == i) {
			for(int j = i * i; j <= N; j += i) 
				if(spf[j] == j)
					spf[j] = i;
		}
	}
}

map<int,int> getFactorization(int x) {
	map<int,int> ret;
	while(x != 1) {
		ret[spf[x]]++;
		x /= spf[x];
	}
	return ret;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
}