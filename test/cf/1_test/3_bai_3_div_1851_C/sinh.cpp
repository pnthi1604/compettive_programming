#include <bits/stdc++.h>

using namespace std;

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

string create_name_file(int n) {
    if (n <= 9)
        return "0" + to_string(n);
    return to_string(n);
}

int main() {
    srand(time(0));
    for (int i = 1; i <= 30; i++) {
        string outputFileName = "input/in" + create_name_file(i) + ".txt";

        ofstream outputFile(outputFileName);

        if (!outputFile) {
            cout << "Không thể tạo hoặc mở file " << outputFileName << endl;
            continue;
        }

        int n, k;
        vector<int> a;
        if (i <= 5) {
            n = random(1, 100);
            k = random(1, n);
        } else if (i <= 10) {
            n = random(1, 1000);
            k = random(1, n);
        } else if (i <= 15) {
            n = random(1001, 10000);
            k = random(1001, n);
        } else if (i <= 20) {
            n = random(10001, (int)1e5);
            k = random(10001, n);
        } else {
            n = random((int)1e5 + 1, (int)2e5);
            k = random((int)1e5 + 1, n);
        }

        int x;
        for(int j = 0; j < n; j++) {
            if (i <= 5) {
                x = random(1, max(1, n / k));  
            } else if (i <= 10) {
                x = random(1, max(1, n / k));  
            } else if (i <= 15) {
                x = random(1, max(1, n / k));  
            } else if (i <= 20) {
                x = random(1, max(1, n / k));
            } else {
                x = random(1, max(1, n / k));
            }
            a.push_back(x);
        }

        outputFile << n << " " << k << endl;
        for (int x : a)
            outputFile << x << ' ';

        outputFile.close();

    }

    return 0;
}
