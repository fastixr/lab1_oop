#include "swap_ab.hpp"

std::string swapAandB(const std::string &input) {
    if (input.empty()) {
        return {};
    }

    std::string result = input;
    for (char &ch : result) {
        switch (ch) {
            case 'a': ch = 'b'; break;
            case 'b': ch = 'a'; break;
            default: break;
        }
    }
    return result;
}


