#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define hi cerr << "HIHIHI" << endl;

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    struct Node {
        int c[26];
        int cnt, exist;
    };

    struct Trie {
        vector<Node> nodes;
        int cur;

        void init(int _n) {
            cur = 0;
            nodes.resize(_n);
            newNode();
        }
        int newNode() {
            nodes[cur].cnt = nodes[cur].exist = 0;
            for(int i = 0; i < 26; i++)
                nodes[cur].c[i] = -1;
            return cur++;
        }
        void addString(string &s) {
            int pos = 0;
            for(char x : s) {
                int y = x - 'a';
                if(nodes[pos].c[y] == -1) 
                    nodes[pos].c[y] = newNode();
                pos = nodes[pos].c[y];
                nodes[pos].cnt++;
            }
            nodes[pos].exist++;
        }
        bool findString(string &s) {
            int pos = 0, i = 0;
            while(pos != -1 && i != s.length()) {
                pos = nodes[pos].c[s[i] - 'a'];
                i++;
            }
            return pos != -1 && nodes[pos].exist != 0;
        }
        bool delString(string &s, int pos, int i) {
            if(i != s.length()) {
                int y = s[i] - 'a';
                bool del = delString(s, nodes[pos].c[y], i + 1);
                if(del)
                    nodes[pos].c[y] = -1;
            } else {
                nodes[pos].exist--;
            }
            if(pos != 0 && --nodes[pos].cnt == 0) return true;
            return false;
        }
        bool delString(string &s) {
            if(findString(s) == false) return false;
            return delString(s, 0, 0);
        }
        int query(string s) {
            int pos = 0;
            for(char x : s) {
                int y = x - 'a';
                pos = nodes[pos].c[y];
                if(pos == -1) return 0;
            }
            return nodes[pos].cnt;
        }
    };
    int n;
    cin >> n;
    Trie t;
    t.init((int)1e5 + 1);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        t.addString(s);
    }
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        cout << s << " co tong so tien to la " << t.query(s) << endl;
    }
    return 0;
}