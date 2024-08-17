#include <bits/stdc++.h>

using namespace std;

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(0));
    for (int i = 1; i <= 100; i++) {
        string outputFileName = "input/in" + to_string(i) + ".txt";

        ofstream outputFile(outputFileName);

        if (!outputFile) {
            cout << "Không thể tạo hoặc mở file " << outputFileName << endl;
            continue;
        }

        int n, k;
        vector<int> a;

        if (i <= 30) {
            n = random(1, 100);
            k = random(1, 100);
        } else if (i <= 80) {
            n = random(101, 1000);
            k = random(101, 1000);
        } else {
            n = random(1001, (int)1e5);
            k = random(1001, n);
        }

        for(int j = 0; j < n; j++) {
            int bit = random(0, 1);
            a.push_back(bit);
        }

        outputFile << n << " " << k << endl;
        for (int x : a)
            outputFile << x;

        outputFile.close();

    }

    return 0;
}
