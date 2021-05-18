#include "gtest/gtest.h"
#include "../include/utility.h"

TEST(TrivUtility, And)
{
    constexpr bool AndTrueExpected00 = triv::And<true, true, true>;
    constexpr bool AndTrueExpected01 = triv::And<true, true, true>;
    EXPECT_TRUE(AndTrueExpected00);
    EXPECT_TRUE(AndTrueExpected01);

    constexpr bool AndFalseExpected00 = triv::And<true, false, true>;
    constexpr bool AndFalseExpected01 = triv::And<false, false, true>;
    constexpr bool AndFalseExpected02 = triv::And<true, 1, 0>;
    EXPECT_FALSE(AndFalseExpected00);
    EXPECT_FALSE(AndFalseExpected01);
    EXPECT_FALSE(AndFalseExpected02);
}

TEST(TrivUtility, Or)
{
    constexpr bool OrTrueExpected00 = triv::Or<false, false, false, true>;
    constexpr bool OrTrueExpected01 = triv::Or<true, false, true, false, true>;
    EXPECT_TRUE(OrTrueExpected00);
    EXPECT_TRUE(OrTrueExpected01);

    constexpr bool OrFalseExpected00 = triv::Or<false, false, false>;
    constexpr bool OrFalseExpected01 = triv::Or<false>;
    constexpr bool OrFalseExpected02 = triv::Or<0, false, 0, 0>;
    EXPECT_FALSE(OrFalseExpected00);
    EXPECT_FALSE(OrFalseExpected01);
    EXPECT_FALSE(OrFalseExpected02);
}