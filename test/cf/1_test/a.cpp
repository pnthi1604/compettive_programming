#include <bits/stdc++.h>

using namespace std;

int main() {
    for (int i = 1; i <= 3; ++i) {
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

        int a, b;
        inputFile >> a >> b;
        int sum = a + b;

        outputFile << "Tổng của " << a << " và " << b << " là: " << sum << endl;

        inputFile.close();
        outputFile.close();

        cout << "Tính toán đã hoàn thành cho " << inputFileName << ". Kết quả đã được ghi vào " << outputFileName << endl;
    }

    return 0;
}
