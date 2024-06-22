#include <iostream>

int process(const int &M, const int &N, const int &x, const int &y)
{
    int m, n;
    bool check[40002] = {};

    m = x;
    if (x > M) return -1;
    n = x;
    if (n > N) n = n - N;

    int cnt = x;
    while (true)
    {
        if (check[n]) return -1;
        if (m == x && n == y) return cnt;

        check[n] = true;

        n = n + M;
        if (n > N) n = n - N;

        cnt += M;
    }
    return -1;
}

int main(void)
{
    int T;

    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int M, N, x, y;
        std::cin >> M >> N >> x >> y;
        if (M > N) { std::swap(M, N); std::swap(x, y); }
        std::cout << process(M, N, x, y) << '\n';
    }

    return 0;
}