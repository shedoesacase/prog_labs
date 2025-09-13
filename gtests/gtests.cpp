#include <gtest/gtest.h>
#include "filter.h"
#include <vector>
#include <tuple>

TEST(filter, parse) {
    std::vector<std::string> input = {
        "192.168.1.1\tbumbum\tafsfsa",
        "10.0.0.1\tqwerty\tdfgsdfgdfg",
        "172.16.0.1\tAAAAAAAAAAAA\tAAAAAAA"
    };

    auto res = parse(input);
    EXPECT_EQ(res[0], std::vector<int>({192,168,1,1}));
    EXPECT_EQ(res[2], std::vector<int>({10,0,0,1}));
}

TEST(filter, firstbit) {
    std::vector<std::vector<int>> ips = {
        {1,1,1,1},
        {2,0,0,1},
        {1,2,3,4}
    };

    auto res = firstbit(ips);
    ASSERT_EQ(res.size(), 2);
    EXPECT_EQ(res[0][0], 1);
    EXPECT_EQ(res[1][0], 1);
}

TEST(FilterTest, firstandsecondbit) {
    std::vector<std::vector<int>> ips = {
        {46,70,1,1},
        {46,1,2,3},
        {1,46,2,3}
    };

    auto res = firstandsecondbit(ips);
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0][0], 46);
    EXPECT_EQ(res[0][1], 70);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
