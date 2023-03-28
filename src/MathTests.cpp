#include "mathLib.h"
#include "gtest/gtest.h"

TEST(MathLibTests, Addition)
{
    EXPECT_EQ(Addition(5, 7), 12);
    EXPECT_EQ(Addition(0, 0), 0);
    EXPECT_EQ(Addition(-128, 5), -123);
    EXPECT_EQ(Addition(-128, -128), -256);
    EXPECT_EQ(Addition(-128, 0), -128);
}

TEST(MathLibTests, Subtraction)
{
    EXPECT_EQ(Subtraction(0, 0), 0);
    EXPECT_EQ(Subtraction(256, 0), 256);
    EXPECT_EQ(Subtraction(1024, 512), 512);
    EXPECT_EQ(Subtraction(512, 1024), -512);
    EXPECT_EQ(Subtraction(-128, -128), 0);
    EXPECT_EQ(Subtraction(-128, 128), -256);
}

TEST(MathLibTests, Multiplication)
{
    EXPECT_EQ(Multiplication(0, 0), 0);
    EXPECT_EQ(Multiplication(0, 1), 0);
    EXPECT_EQ(Multiplication(1, 1), 1);
    EXPECT_EQ(Multiplication(-1, -1), 1);
    EXPECT_EQ(Multiplication(-1, 1), -1);
    EXPECT_EQ(Multiplication(-256, 2), -512);
    EXPECT_EQ(Multiplication(-256, -2), 512);
}

TEST(MathLibTests, Division)
{
    EXPECT_THROW(Division(1, 0), std::overflow_error);
    EXPECT_THROW(Division(0, 0), std::overflow_error);
    EXPECT_EQ(Division(0, 1), 0);
    EXPECT_EQ(Division(2, 1), 2);
    EXPECT_EQ(Division(10, 2), 5);
    EXPECT_EQ(Division(128, 2), 64);
    EXPECT_EQ(Division(256, 2), 128);
    EXPECT_EQ(Division(512, 4), 128);
    EXPECT_EQ(Division(-256, 2), -128);
    EXPECT_EQ(Division(-512, 2), -256);
    EXPECT_EQ(Division(-512, 4), -128);
    EXPECT_EQ(Division(32767, 8), 4095.875);
}

TEST(MathLibTests, Power)
{
    // Test integer powers
    EXPECT_EQ(Power(2, 0), 1);
    EXPECT_EQ(Power(2, 1), 2);
    EXPECT_EQ(Power(2, 2), 4);
    EXPECT_EQ(Power(2, 3), 8);
    EXPECT_EQ(Power(3, 4), 81);

    // Test negative bases
    EXPECT_EQ(Power(-2, 0), 1);
    EXPECT_EQ(Power(-2, 1), -2);
    EXPECT_EQ(Power(-2, 2), 4);
    EXPECT_EQ(Power(-2, 3), -8);
}

TEST(MathLibTests, Factorial)
{
    EXPECT_EQ(Factorial(0), 1);
    EXPECT_EQ(Factorial(1), 1);
    EXPECT_EQ(Factorial(2), 2);
    EXPECT_EQ(Factorial(3), 6);
    EXPECT_EQ(Factorial(4), 24);
    EXPECT_EQ(Factorial(5), 120);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}