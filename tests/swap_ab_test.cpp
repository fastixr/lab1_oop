#include <gtest/gtest.h>
#include "swap_ab.hpp"

TEST(SwapAB, Examples) {
    EXPECT_EQ(swapAandB("acb"), "bca");
    EXPECT_EQ(swapAandB("aabacbaa"), "bbabcabb");
}

TEST(SwapAB, EdgeCases) {
    EXPECT_EQ(swapAandB("") , "");
    EXPECT_EQ(swapAandB("c"), "c");
    EXPECT_EQ(swapAandB("aaaa"), "bbbb");
    EXPECT_EQ(swapAandB("bbbb"), "aaaa");
    EXPECT_EQ(swapAandB("ccccccc"), "ccccccc");
    EXPECT_EQ(swapAandB("abcabc"), "bacbac");
}


