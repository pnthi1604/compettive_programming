#include <bits/stdc++.h>
#define ll long long
#define infInt (int)1e9 + 1
// #define infLL 0x3f3f3f3f3f3f
#define infLL (int)1e17
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define vtttt vector<vttt>
#define pii pair<int, int>
#define vpii vector<pii>
#define endl '\n'
#define all(a) a.begin(), a.end()
#define _sort(a) sort(all(a))
#define bsUp(a, x) upper_bound(all(a), x) - a.begin()
#define bsLow(a, x) lower_bound(all(a), x) - a.begin()
#define rev(a) reverse(all(a))
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
#define int ll
#define hi ;
using namespace std;

struct Fraction {
    int a, b;

    Fraction(int _a, int _b) {
        int g = gcd(abs(_a), abs(_b));
        a = _a / g;
        b = _b / g;
    }

    Fraction operator * (Fraction &o) {
        Fraction res(a * o.a, b * o.b);
        return res;
    }

    Fraction operator + (Fraction &o) {
        Fraction res(a * o.b + b * o.a, b * o.b);
        return res;
    }

    Fraction operator - (Fraction &o) {
        Fraction res(a * o.b - b * o.a, b * o.b);
        return res;
    }

    Fraction operator / (Fraction &o) {
        Fraction inverseO(o.b, o.a);
        return (*this) * inverseO;
    }

    long double getAns() {
        return (long double)a / b;
    }

    void print() {
        cout << a << "/" << b << endl;
    }
};

void in(Fraction a) {
    cout << a.getAns() << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    int c, d;
    cin >> c >> d;
    Fraction ps1(a, b), ps2(c, d);
    Fraction sum = ps1 + ps2, sub = ps1 - ps2, mul = ps1 * ps2, div = ps1 / ps2;
    sum.print();
    in(sum);
    sub.print();
    in(sub);
    mul.print();
    in(mul);
    div.print();
    in(div);
    return 0;
}
