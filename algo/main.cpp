#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define hi cerr << "HIHIHI" << endl;

using namespace std;

const int N = (int)1e5 + 10;
int a[N];
int n, m, k;
int cnt[(1 << 31)];
int ans[N];
int p[N];
struct query {
    int l, r, id;
};
vector<query> queries;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] ^ a[i];
    }
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i});
    }
    int B = (int)sqrt(n);
    int res = 0;
    sort(queries.begin(), queries.end(), [&](query a, query b) -> bool {
        auto[la, ra, ida] = a;
        auto[lb, rb, idb] = b;
        if(la / B != lb / B)
            return la / B < lb / B;
        return ra < rb;
        }
    );
    auto add = [&](int i) -> void {
        cnt[p[i]]++;
        res += cnt[p[i] ^ k];
    };
    auto del = [&](int i) -> void {
        res -= cnt[p[i] ^ k];
        cnt[p[i]]--;
    };
    int cur_l = 1, cur_r = 0;
    for(auto[l, r, id] : queries) {
        while(cur_l > l)
            add(--cur_l);   
        while(cur_r < r)
            add(++cur_r);
        while(cur_l < l)
            del(cur_l++);
        while(cur_r > r)
            del(cur_r--);
        ans[id] = res;
    }
    for(int i = 0; i < m; i++)
        cout << ans[i] << endl;
    return 0;
}