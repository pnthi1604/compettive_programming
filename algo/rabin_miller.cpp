// Tính a^k mod n
long long binaryPower(long long a, long long k, long long n)
{
    a = a % n;
    long long res = 1;
    while (k)
    {
        if (k & 1)
            res = (res * a) % n;
        a = (a * a) % n;
        k /= 2;
    }
    return res;
}

// Kiểm tra điều kiện thuật toán với a cố định
bool test(long long a, long long n, long long k, long long m)
{
    long long mod = binaryPower(a, m, n);
    if (mod == 1 || mod == n - 1)
            return true;
    for (int l = 1; l < k; ++l)
    {
        mod = (mod * mod) % n;
        if (mod == n - 1)
            return true;
    }
    return false;
}

bool RabinMiller(long long n)
{
    // Kiểm tra với các giá trị nhỏ
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;
    if (n < 11)
        return false;

    // Tính m và k
    long long k = 0, m = n - 1;
    while (m % 2 == 0)
    {
        m /= 2;
        k++;
    }

    // Lặp lại bước kiểm tra với a ngẫu nhiên
    const static int repeatTime = 3;
    for (int i = 0; i < repeatTime; ++i)
    {
        long long a = rand() % (n - 3) + 2;
        if (!test(a, n, k, m))
            return false;
    }
    return true;
}