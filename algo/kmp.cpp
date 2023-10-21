#include <bits/stdc++.h>
#define int long long
using namespace std;

void kmp(string s, string t) {
    //xay dung mang pi
    vector<int> pi(s.length());
    int k = 0;
    pi[0] = 0;
    for(int i = 1; i < s.length(); ++i) {
        while(k && s[k] != s[i])
            k = pi[k - 1];
        if(s[k] == s[i])
            ++k;
        pi[i] = k;
    }

    //so khop
    k = 0;
    for(int i = 0; i < t.length(); ++i) {
        while(k && s[k] != t[i])
            k = pi[k - 1];
        if(s[k] == t[i])
            ++k;
        if(k == s.length())
            cout << "find true index of t is " << i - s.length() + 1 << endl, k = pi[k - 1];
    }
}

void kmp_ver_2(string s, string t) {
    vector<int> pi(s.length());
    pi[0] = 0;
    int j = 0;
    for(int i = 1; i < s.length(); ++i) {
        while(s[j] != s[i]) {
            if(j == 0) {
                j = -1;
                break;
            } else j = pi[j - 1];
        }
        pi[i] = j + 1;
        ++j;
    }
    j = 0;
    for(int i = 0; i < t.length(); ++i) {
        while(j && s[j] != t[i])
            j = pi[j - 1];
        if(s[j] == t[i])
            ++j;
        if(j == s.length())
            cout << i - s.length() + 2 << ' ', j = pi[j - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    kmp_ver_2(s, t);
}