#include <bits/stdc++.h>
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
#define int long long
using namespace std;

const int N = (int)1e7 + 1;
const int base = 37;
const int base1 = 29;
const int mod = (int)1e9 + 9;
const int mod1 = (int)1e9 + 7;

int p[N];
int p1[N];

void calPow(int n) {
    p[0] = 1;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] * base % mod;
}

void calHash(string s, vt &h) {
    h.resize(s.length() + 1);
    h[0] = 0;
    for(int i = 1; i <= s.length(); ++i)
        h[i] = h[i - 1] * base + s[i - 1] - 'a' + 1, h[i] %= mod;
}

void calPow1(int n) {
    p1[0] = 1;
    for(int i = 1; i <= n; i++)
        p1[i] = p1[i - 1] * base1 % mod1;
}

void calHash1(string s, vt &h) {
    h.resize(s.length() + 1);
    h[0] = 0;
    for(int i = 1; i <= s.length(); ++i)
        h[i] = h[i - 1] * base1 + s[i - 1] - 'a' + 1, h[i] %= mod1;
}

int getHash(int i, int j, vt &h) {
    i++; j++;
    return (h[j] - h[i - 1] * p[j - i + 1] + mod * mod) % mod;
}

int getHash1(int i, int j, vt &h) {
    i++; j++;
    return (h[j] - h[i - 1] * p1[j - i + 1] + mod1 * mod1) % mod1;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    int k; cin >> k;
    int n = s.size(), m = t.size();
    vt d(256, 1);
    for(int i = 0; i < m; i++) {
        if(t[i] != '0')
            d[i + 'a'] = 0;
    }
    vt l(n), r(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            l[i] += d[s[i]], r[n - i - 1] += d[s[n - i - 1]];
        } else {
            l[i] += l[i - 1] + d[s[i]], r[n - i - 1] += r[n - i] + d[s[n - i - 1]];
        }
        sum += d[s[i]];
    }
    vt h_s, h_s1;
    calPow(n);
    calHash(s, h_s);
    calPow1(n);
    calHash1(s, h_s1);
    set<pii> cnt;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int _sum = 0;
            if(i - 1 >= 0)
                _sum += l[i - 1];
            if(j + 1 <= n - 1)
                _sum += r[j + 1];
            if(sum - _sum <= k)
                cnt.insert(make_pair(getHash(i, j, h_s), getHash1(i, j, h_s1)));
        }
    }
    cout << cnt.size();
}
