#include <iostream>
#include <string>
#include "swap_ab.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) {
        return 0;
    }
    std::cout << swapAandB(s) << '\n';
    return 0;
}


