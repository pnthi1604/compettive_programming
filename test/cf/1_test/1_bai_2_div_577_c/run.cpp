#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main() {
    for (int i = 1; i <= 100; ++i) {
        string inputFileName = "input/in" + to_string(i) + ".txt";
        string outputFileName = "output/out" + to_string(i) + ".txt";

        ifstream inputFile(inputFileName);
        ofstream outputFile(outputFileName);

        if (!inputFile) {
            cout << "Không thể mở file " << inputFileName << endl;
            continue;
        }
        if (!outputFile) {
            cout << "Không thể tạo hoặc mở file " << outputFileName << endl;
            continue;
        }

        int n, k, mid_idx;
        inputFile >> n >> k >> mid_idx;
        mid_idx--;
        vector<int> a(n);
        for(int &x : a) 
            inputFile >> x;
        sort(a.begin(), a.end());

        int l = 0, r = n - 1, res = mid_idx, _sum = 0;
        while(l <= r) {
            int m = (l + r) / 2;
            ll sum = 0;
            for (int j = mid_idx; j <= m; j++)
                sum += a[m] - a[j];
            if (sum <= k) {
                res = m;
                l = m + 1;
                _sum = sum;
            } else {
                r = m - 1;
            }
        }
        k -= _sum;
        outputFile << a[res] + k / (res - mid_idx + 1);

        inputFile.close();
        outputFile.close();

        cout << "Tính toán đã hoàn thành" << endl;
    }

    return 0;
}
