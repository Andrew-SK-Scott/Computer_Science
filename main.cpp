/*
Date : 6/23/2024 ( 1 : 35 am )
problem : #6064 ( baekjoon )
 - Link : https://www.acmicpc.net/problem/6064
*/
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

        // Q. why I have to swap(M, N) and swap(x, y)?
        // A. try example_1 - fourth line
        if (M > N) { std::swap(M, N); std::swap(x, y); }
        std::cout << process(M, N, x, y) << '\n';
    }

    return 0;
}