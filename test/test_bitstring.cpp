#include <gtest/gtest.h>
#include "../include/bitstring.h"

TEST(BitStringTest, BasicOperations) {
    BitString bs1("1010");
    BitString bs2("1100");

    EXPECT_EQ(bs1.AND(bs2).toString(), "1000");
    EXPECT_EQ(bs1.OR(bs2).toString(), "1110");
    EXPECT_EQ(bs1.XOR(bs2).toString(), "0110");
    EXPECT_EQ(bs1.NOT().toString(), "0101");
}

TEST(BitStringTest, DifferentLengths) {
    BitString bs1("1010");
    BitString bs2("110");

    EXPECT_EQ(bs1.AND(bs2).toString(), "1000");
    EXPECT_EQ(bs1.OR(bs2).toString(), "1110");
}

TEST(BitStringTest, InvalidInput) {
    EXPECT_THROW(BitString invalid("1020"), std::invalid_argument);
}