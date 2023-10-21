const int N = (int) 1e8;
bitset<N / 2 + 1> isPrime;
void sieve(int n = N) {
    isPrime.flip();
    isPrime[0] = false;
    for (int i = 3; i <= (int) sqrt(n); i += 2) {
        if (isPrime[i >> 1]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                isPrime[j >> 1] = false;
            }
        }
    }
}
void example(int n) {
    sieve(n);
    int primeCnt = (n >= 2);
    for (int i = 3; i <= n; i += 2) {
        if (isPrime[i >> 1]) {
            primeCnt++;
        }
    }
    cout << primeCnt << '\n';
}