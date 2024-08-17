#include <bits/stdc++.h>
using namespace std;

void dfs(int x) {
    if (x % 1000 == 0) cout << x << endl;

    vector<int> v;
    for (int i = 0; i < 20; i++) v.push_back(x ^ i);

    dfs(x + 1);
}

int main(void) {
    dfs(0);
}
