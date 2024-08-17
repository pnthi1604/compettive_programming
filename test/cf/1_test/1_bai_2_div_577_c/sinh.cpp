#include <bits/stdc++.h>

using namespace std;

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(0));
    for (int i = 1; i <= 30; i++) {
        string outputFileName = "input/in" + to_string(i) + ".txt";

        ofstream outputFile(outputFileName);

        if (!outputFile) {
            cout << "Không thể tạo hoặc mở file " << outputFileName << endl;
            continue;
        }

        int n, k, h;

        if (i <= 30) {
            n = random(1, 100);
            k = random(1, 100);
            h = random(1, n);
        } else if (i <= 80) {
            n = random(101, 1000);
            k = random(101, 1000);
            h = random(1, n);
        } else {
            n = random(1001, (int)2e5);
            k = random(1001, (int)(1e9));
            h = random(1, n);
        }

        vector<int> a(n);
        for (int &x : a)
            x = random(1, (int)1e9);

        outputFile << n << " " << k << " " << h << endl;
        for (int x : a)
            outputFile << x << " ";

        outputFile.close();

    }

    return 0;
}
