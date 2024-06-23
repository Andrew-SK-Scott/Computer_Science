/*
Date : 06/23/2024
problem : #7662 ( baekjoon )
 - Link : https://www.acmicpc.net/problem/7662
*** main STL ***
set
*/
#include <iostream>
#include <set>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int T;

    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int k;
        std::multiset<int> s; // duplicate allowed

        std::cin >> k;
        for (int j = 0; j < k; j++) {
            int n;
            char command;
            std::cin >> command >> n;

            if (command == 'I') s.insert(n);
            else if (command == 'D') {
                if (s.empty()) continue; // when s is empty, if you use s.erase(n), it errors

                if (n == 1) 
                    /* std::prev(s.end()) -> s.end() returns s's end of the address one space behind,
                       so if you use std::prev(address), std::prev() returns one space ahead */
                    s.erase(std::prev(s.end()));
                else s.erase(s.begin());
            }
        }
        if (s.empty()) std::cout << "EMPTY\n";
        else std::cout << *std::prev(s.end()) << ' ' << *s.begin() << '\n';
    }

    return 0;
}