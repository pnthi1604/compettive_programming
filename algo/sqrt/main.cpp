#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define hi cerr << "HIHIHI" << endl;

using namespace std;

const int N = (int)1e5 + 10;
int a[N];
int n, m, k;
ll cnt[1 << 20];
ll ans[N];
int x[N];
int B;

struct query {
    int l, r, id;
    bool operator<(query o) const {
        int l1 = l / B, l2 = o.l / B;
        if(l1 != l2) return l1 < l2;
        return r < o.r;
    }
};
vector<query> queries;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        x[i] = x[i - 1] ^ a[i];
    }
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l - 1, r, i});
    }
    B = (int)sqrt(n);
    ll res = 0;
    sort(queries.begin(), queries.end());
    auto add = [&](int i) -> void {
        res += cnt[x[i] ^ k];
        cnt[x[i]]++;
    };
    auto del = [&](int i) -> void {
        cnt[x[i]]--;
        res -= cnt[x[i] ^ k];
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