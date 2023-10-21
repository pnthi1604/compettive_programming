#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
mt19937 rd(time(0));

int max(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int rand(int l, int h) {
    return l + rd() * rd() % (h - l + 1);
}

//su dung cac bien global de in ra test sai
struct qr {
    int x1, y1, x2, y2, k;
};
int n, q;
vector<vector<int>> a;
vector<qr> qrs;
string name = "cf";

//tao test cho file in.txt
void makeTest() {
    ofstream cout("in.txt");
    n = 3;
    q = 1;
    a.assign(n, vector<int>(n, 0));
    cout << n << ' ' << q << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = rand(1, (int)1e9);
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    qrs.resize(q);
    for(int i = 0; i < q; i++) {
        qrs[i].x1 = rand(1, n - 1);
        qrs[i].y1 = rand(1, n - 1);
        qrs[i].x2 = min(qrs[i].x1 + 2, n);
        qrs[i].y2 = min(qrs[i].y1 + 2, n);
        int cnt = 0;
        for(int ii = qrs[i].x1; ii <= qrs[i].x2; ii++)
            for(int j = qrs[i].y1; j <= qrs[i].y2; j++) 
                cnt++;
        qrs[i].k = max(1, cnt - 1);
        cout << qrs[i].x1 << ' ' << qrs[i].y1 << ' ' << qrs[i].x2 << ' ' << qrs[i].y2 << ' ' << qrs[i].k << endl;
    } 
}   

const int n_test = 100000000;//so luong test toi da de kiem tra

signed main() {
    srand(time(0));
    for(int i = 1; i <= n_test; ++i) {
        makeTest();
        // system("./cf <in.txt> out.txt");
        // system("./cf_trau <in.txt> ans.txt");
        system(("./" + name + " <in.txt> out.txt").c_str());
        system(("./" + name + "_trau" + " <in.txt> ans.txt").c_str());
        if (system("diff out.txt ans.txt") != 0) {
            cout << "WRONG! on test " << i << endl;
            //in ra console test sai o day
            return 0;
        }
        cout << "TEST " << i << ": CORRECT!\n";
    }
}
