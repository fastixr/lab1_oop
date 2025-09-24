#include "swap_ab.hpp"

std::string swapAandB(const std::string &input) {
    std::string result;
    result.reserve(input.size());
    for (char ch : input) {
        if (ch == 'a') {
            result.push_back('b');
        } else if (ch == 'b') {
            result.push_back('a');
        } else {
            result.push_back(ch);
        }
    }
    return result;
}


