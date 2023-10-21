#include <bits/stdc++.h>
#define ll long long
#define infInt (int)1e9 + 1
// #define infLL 0x3f3f3f3f3f3f
#define infLL (int)1e17
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define vtttt vector<vttt>
#define pii pair<int, int>
#define vpii vector<pii>
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

const int nmax = (int)1e5 + 1;

struct Node {
    int child[26];
    int exist, cnt;
    //exist: the number of strings is represented by vertex u
    //cnt: the number of prefix is represented by vertex u
};

struct Trie {
    int cur;
    vector<Node> nodes;

    int newNode() {
        for(int i = 0; i < 26; i++)
            nodes[cur].child[i] = -1;
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur++;
    }

    void init(int n) {
        nodes.resize(n);
        cur = 0;
        newNode();
    }

    void addString(string &s) {
        int pos = 0;
        for(char x : s) {
            int c = x - 'a';
            if(nodes[pos].child[c] == -1)
                nodes[pos].child[c] = newNode();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    bool delString(int pos, string &s, int i) {
        if(i < s.length()) {
            int c = s[i] - 'a';
            bool isDel = delString(nodes[pos].child[c], s, i + 1);
            if(isDel)
                nodes[pos].child[c] = -1;
        } else {
            nodes[pos].exist--;
        }
        if(pos != 0) {
            nodes[pos].cnt--;
            return nodes[pos].cnt == 0;
        }
        return false;
    }

    bool findString(string &s) {
        int pos = 0, ids = 0;
        while(ids < s.length() && pos != -1) {
            pos = nodes[pos].child[s[ids] - 'a'];
            ids++;
        }
        return pos != -1 && nodes[pos].exist != 0;
    }

    void delString(string &s) {
        if(findString(s))
            delString(0, s, 0);
    }

    int query(string &s) {
        int pos = 0;
        for(char x : s) {
            int c = x - 'a';
            pos = nodes[pos].child[c];
            if(pos == -1)
                return 0;
        }
        return nodes[pos].cnt;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    Trie t;
    t.init(nmax);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        t.addString(s);
    }
    int q;
    cin >> q;
    while(q--) {
        int tt;
        cin >> tt;
        if(tt == 1) {
            string s;
            cin >> s;
            t.delString(s);
            cerr << "da xoa chuoi: " << s << endl;
        } else {
            string s;
            cin >> s;
            cerr << "ket qua la: ";
            cerr << t.query(s) << endl;
        }
    }
}