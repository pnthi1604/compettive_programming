#include <bits/stdc++.h>
#define int long long
#define float double

using namespace std;

long long randomInRange(long long l, long long r) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<long long> dis(l, r);
    return dis(gen);
}

double randomDoubleInRange(double l, double r) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(l, r);
    return dis(gen);
}

string output_file(int n) {
    ostringstream oss;
    oss << "/home/phamngocthi/cp/test/output/output" << setw(2) << setfill('0') << n << ".txt";
    string filename = oss.str();
    return filename;
}

string input_file(int n) {
    ostringstream oss;
    oss << "/home/phamngocthi/cp/test/input/input" << setw(2) << setfill('0') << n << ".txt";
    string filename = oss.str();
    return filename;
}

/*Các giá trị sinh*/
int n_test = 20;

void input() {
    for(int i = 0; i < n_test; i++) {
        freopen(input_file(i).c_str(), "w", stdout);
        int a, b;
        a = randomInRange(1, 100);
        b = randomInRange(101, 200);
        cout << a << ' ' << b << endl;
        fclose(stdout);
    }
}

void output() {
    for(int i = 0; i < 20; i++) {
        /*Đọc từ file input*/
        freopen(input_file(i).c_str(), "r", stdin);
        int a, b;
        cin >> a >> b;
        cout << a << ' ' << b << endl;
        fclose(stdin);
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    return 0;
}