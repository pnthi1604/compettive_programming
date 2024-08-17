#include <bits/stdc++.h>
#define ll long long

using namespace std;

string create_name_file(int n) {
    if (n <= 9)
        return "0" + to_string(n);
    return to_string(n);
}

int32_t main() {
    for (int i = 1; i <= 30; ++i) {
        string inputFileName = "input/in" + create_name_file(i) + ".txt";
        string outputFileName = "output/out" + create_name_file(i) + ".txt";

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

        // Giải thuật
        int n, d;
        inputFile >> n >> d;
        vector<int> a(n);
        for(int &x : a)
            inputFile >> x;
        int ans = -1;
        int cnt_an = 0;
        for (int x : a)
            cnt_an += x == a[n - 1];
        if (a[0] == a[n - 1]) {
            if (cnt_an >= d) 
                ans = d;
        } else {
            if (cnt_an >= d) {
                int cnt_a0 = 0;
                int need_cnt_an = d;
                for(int j = n - 1; j >= 0; j--) {
                    need_cnt_an -= a[j] == a[n - 1];
                    //need_cnt_an <= 0: Bên phải mảng đã duyệt qua được d phần tử bằng a_n rồi
                    if (a[j] == a[0] && need_cnt_an <= 0) 
                        cnt_a0++;
                }
                if(cnt_a0 >= d)
                    ans = 2 * d;
            }
        }
        outputFile << ans << endl;

        inputFile.close();
        outputFile.close();
    }

    return 0;
}
