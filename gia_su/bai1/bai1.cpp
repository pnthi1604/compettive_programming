#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct MemType {
    int len;
    int index_first;
    int index_second;
};

ll dp1[11][3], dp2[11][3];
MemType max_num1[11][3], max_num2[11][3];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int query;
    cin >> query;
    vector<int> a(1, 0);
    for (char c : s)
        a.push_back(c - '0');

    int n = a.size() - 1;
    for (int j = 0; j < 11; j++) {
        for (int k = 0; k < 3; k++) {
            dp1[j][k] = 0;
            max_num1[j][k] = {0, -1, -1};
        }
    }

    int max_len = -1, index_first_max = -1, index_second_max = -1, last_index = -1;

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        dp2[a[i] % 11][a[i] % 3] += 1;
        max_num2[a[i] % 11][a[i] % 3] = {1, i, -1};
        for (int j = 0; j < 11; j++) {
            for (int k = 0; k < 3; k++) {
                int new_j = (j * 10 + a[i]) % 11;
                int new_k = (k * 10 + a[i]) % 3;
                dp2[new_j][new_k] += dp1[j][k];
                if (max_num1[j][k].len > 0) {
                    int cur_len = max_num2[new_j][new_k].len;
                    int pre_len = max_num1[j][k].len + 1;
                    if (cur_len < pre_len) {
                        if (max_num1[j][k].index_second != -1) {
                            max_num2[new_j][new_k] = max_num1[j][k];
                            max_num2[new_j][new_k].len = pre_len;
                        } else {
                            int index_first = max_num1[j][k].index_first;
                            if (a[index_first] != a[i]) {
                                max_num2[new_j][new_k] = {pre_len, i - 1, i};
                            } else {
                                max_num2[new_j][new_k] = {pre_len, i, -1};                            
                            }
                        }
                    }
                    else if (cur_len == pre_len) {
                        int index_first = max_num1[j][k].index_first;
                        int index_second = max_num1[j][k].index_second;
                        if (index_first != -1 && index_second != -1) {
                            if (a[index_first] < a[index_second]) {
                                max_num2[new_j][new_k] = max_num1[j][k];
                                max_num2[new_j][new_k].len = pre_len;
                            }
                        }
                    }
                }
            }
        }
        ans += dp2[0][0];
        if (i == 1) {
            max_len = max_num2[0][0].len, index_first_max = max_num2[0][0].index_first, index_second_max = max_num2[0][0].index_second, last_index = i;
        } else {
            int index_first = max_num2[0][0].index_first;
            int index_second = max_num2[0][0].index_second;
            if (index_second == -1) {
                index_second = index_first;
            }
            int len = max_num2[0][0].len;
            if (max_len < len) {
                max_len = len;
                index_first_max = index_first;
                index_second_max = index_second;
                last_index = i;
            } else if (max_len == len) {
                if (a[index_first_max] < a[index_first]) {
                    index_first_max = index_first;
                    index_second_max = index_second;
                    last_index = i;
                } else if (a[index_first_max] == a[index_first]) {
                    if (index_second_max != -1 && a[index_second_max] < a[index_second]) {
                        index_first_max = index_first;
                        index_second_max = index_second;
                        last_index = i;
                    }
                }
            }
        }
        for (int j = 0; j < 11; j++) {
            for (int k = 0; k < 3; k++) {
                dp1[j][k] = dp2[j][k];
                max_num1[j][k] = max_num2[j][k];
                dp2[j][k] = 0;
                max_num2[j][k] = {0, -1, -1};
            }
        }
    }

    if (query == 1) {
        cout << ans;
    } else {
        if (index_first_max <= index_second_max) {
            for (int i = last_index - max_len + 1; i <= last_index; i++) {
                cout << a[i];
            }
        } else {
            cout << -1;
        }
    }
    return 0;
}
