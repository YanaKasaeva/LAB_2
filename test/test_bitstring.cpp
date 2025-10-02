#include <gtest/gtest.h>
#include "../include/bitstring.h"

TEST(BitStringTest, Constructors) {
    BitString empty;
    EXPECT_EQ(empty.length(), 0);

    BitString fromString("1010");
    EXPECT_EQ(fromString.toString(), "1010");

    BitString copy(fromString);
    EXPECT_EQ(copy.toString(), "1010");
}

TEST(BitStringTest, ANDOperation) {
    BitString bs1("1010");
    BitString bs2("1100");
    BitString result = bs1.AND(bs2);
    EXPECT_EQ(result.toString(), "1000");
}

TEST(BitStringTest, OROperation) {
    BitString bs1("1010");
    BitString bs2("1100");
    BitString result = bs1.OR(bs2);
    EXPECT_EQ(result.toString(), "1110");
}

TEST(BitStringTest, XOROperation) {
    BitString bs1("1010");
    BitString bs2("1100");
    BitString result = bs1.XOR(bs2);
    EXPECT_EQ(result.toString(), "0110");
}

TEST(BitStringTest, NOTOperation) {
    BitString bs1("1010");
    BitString result = bs1.NOT();
    EXPECT_EQ(result.toString(), "0101");
}

TEST(BitStringTest, Exceptions) {
    EXPECT_THROW(BitString invalid("1020"), std::invalid_argument);
}

TEST(BitStringTest, DifferentLengths) {
    BitString bs1("1010");
    BitString bs2("110");

    BitString or_result = bs1.OR(bs2);
    EXPECT_EQ(or_result.toString(), "1110");

    BitString and_result = bs1.AND(bs2);
    EXPECT_EQ(and_result.toString(), "1000");

    BitString xor_result = bs1.XOR(bs2);
    EXPECT_EQ(xor_result.toString(), "0110");
}