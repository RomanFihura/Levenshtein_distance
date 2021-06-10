#include "Levenshtein_distance.h"

#include <gtest/gtest.h>

TEST(Test1, strings_equal)
{
    Levenshtein_distance test("Roman", "Roman");
    EXPECT_EQ(test.Levenshtein_distance_result(), 0);
}
TEST(Test2, str1_less_that_str2)
{
    Levenshtein_distance test("Rom", "Roman");
    EXPECT_EQ(test.Levenshtein_distance_result(), 2);
}
TEST(Test3, str2_less_that_str1)
{
    Levenshtein_distance test("Roman", "Ro");
    EXPECT_EQ(test.Levenshtein_distance_result(), 3);
}
TEST(Test4, str1_is_empty)
{
    Levenshtein_distance test("", "Ro");
    EXPECT_EQ(test.Levenshtein_distance_result(), 2);
}
TEST(Test5, str2_is_empty)
{
    Levenshtein_distance test("HelloWorld", "");
    EXPECT_EQ(test.Levenshtein_distance_result(), 10);
}

