#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = (int)2e5;
const int K = 26;
int st[K][N], a[N], n, lg[N];

signed main()
{
    freopen("/home/phamngocthi/cp/input.txt", "r", stdin);
    freopen("/home/phamngocthi/cp/output.txt", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    copy(a, a + n, st[0]);
    for(int i = 1; i <= K; i++)
    {
        for(int j = 0; j + (1 << i) - 1 < n; j++)
        {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    lg[1] = 0;
    for(int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    auto rmq = [&](int L, int R)
    {
        int i = lg[R - L + 1];
        return min(st[i][L], st[i][R - (1 << i) + 1]);
        //O(1)
    };
    int t;
    cin >> t;
    while(t--)
    {
        int l, r;
        cin >> l >> r;
        cout << l << ' ' << r << '\n' << rmq(l - 1, r - 1) << '\n';
    }
    return 0;
}