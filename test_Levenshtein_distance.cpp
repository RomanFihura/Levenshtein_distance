#include "Levenshtein_distance.h"

#include <gtest/gtest.h>

TEST(Test1, strings_equal)
{
    EXPECT_EQ(Levenshtein_distance("Roman", "Roman"), 0);
}
TEST(Test2, str1_less_that_str2)
{
    EXPECT_EQ(Levenshtein_distance("Rom", "Roman"), 2);
}
TEST(Test3, str2_less_that_str1)
{
    EXPECT_EQ(Levenshtein_distance("Roman", "Ro"), 3);
}
TEST(Test4, str1_is_empty)
{
    EXPECT_EQ(Levenshtein_distance("", "Ro"), 2);
}
TEST(Test5, str2_is_empty)
{
    EXPECT_EQ(Levenshtein_distance("HelloWorld", ""), 10);
}
TEST(Test6, Levenstrain_properly_work)
{
    EXPECT_EQ(Levenshtein_distance("Roan", "Roman"), 1);
    
}
