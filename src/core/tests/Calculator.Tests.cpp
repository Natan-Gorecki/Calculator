#include <functional>
#include "Calculator.h"
#include "gtest/gtest.h"

using namespace std;
TEST(CalculatorTests, Calculate_ShouldHandleAddition)
{
    auto calculator = make_unique<Calculator>();
    
    ASSERT_EQ(calculator->Calculate("2 + 2"), 4.0);
    ASSERT_EQ(calculator->Calculate("2 + 4 + 8"), 14.0);
    ASSERT_EQ(calculator->Calculate("2 + (-2) + 5"), 5.0);
    ASSERT_EQ(calculator->Calculate("-2 + 2"), 0.0);
    ASSERT_EQ(calculator->Calculate("-2.5 + 2"), -0.5);
    ASSERT_EQ(calculator->Calculate("-2,5 + 2.5"), 0.0);
}

TEST(CalculatorTests, Calculate_ShouldHandleSubstraction)
{
    auto calculator = make_unique<Calculator>();

    ASSERT_EQ(calculator->Calculate(" 2- 7"), -5.0);
    ASSERT_EQ(calculator->Calculate("-2 - 7 -5"), -14.0);
    ASSERT_EQ(calculator->Calculate("-2 - (-7)"), 5.0);
    ASSERT_EQ(calculator->Calculate(" 0.5 - 7,2"), -6.7);
}

TEST(CalculatorTests, Calculate_ShouldHandleMultiplication)
{
    auto calculator = make_unique<Calculator>();

    ASSERT_EQ(calculator->Calculate(" 2 * 4"), 8.0);
    ASSERT_EQ(calculator->Calculate("2 * (-5)"), -10.0);
    ASSERT_EQ(calculator->Calculate("1/2 * (-1/2)"), -0.25);
    ASSERT_EQ(calculator->Calculate(" 2 * 4 * (1/2)"), 4.0);
}

TEST(CalculatorTests, Calculate_ShouldHandleDivision)
{
    auto calculator = make_unique<Calculator>();

    ASSERT_EQ(calculator->Calculate("16 / 2 / 5"), 1.6);
    ASSERT_EQ(calculator->Calculate("16 / (-2) / 5"), -1.6);
    ASSERT_EQ(calculator->Calculate("1/2 / (-1/2)"), -1.0);
    ASSERT_EQ(calculator->Calculate(" 2 / 4 / (1/2)"), 1.0);
}

TEST(CalculatorTests, Calculate_ShouldHandleBrackets)
{
    auto calculator = make_unique<Calculator>();

    ASSERT_EQ(calculator->Calculate("((((2))))"), 2.0);
    ASSERT_EQ(calculator->Calculate("(((2.5)(-4.4))-2)"), -13.0);
    ASSERT_EQ(calculator->Calculate("(2 + 5) * 2"), 14.0);
    ASSERT_EQ(calculator->Calculate("(2 * 5 - 2) * (4.5 - 2 / 8)"), 34.0);
}

TEST(CalculatorTests, Calculate_ShouldHandleMultiplication_WhenCharacterIsHidden)
{
    auto calculator = make_unique<Calculator>();

    ASSERT_EQ(calculator->Calculate("2(5-7)"), -4.0);
    ASSERT_EQ(calculator->Calculate("(5-7)2"), -4.0);
    ASSERT_EQ(calculator->Calculate("(3-5)(5-3)"), -4.0);
    ASSERT_EQ(calculator->Calculate("(2 + 5) * 2(2+7)"), 126.0);
    ASSERT_EQ(calculator->Calculate("-6(2(2))"), -24.0);
}

TEST(CalculatorTests, Calculate_ShouldHandleCharacterAtTheBeginning)
{
    auto calculator = make_unique<Calculator>();

    ASSERT_EQ(calculator->Calculate("+7"), 7.0);
    ASSERT_EQ(calculator->Calculate("-2 + (-7)"), -9.0);
}

TEST(CalculatorTests, Calculate_ShouldHandleFractions_WithDots)
{
    auto calculator = make_unique<Calculator>();

    ASSERT_EQ(calculator->Calculate(".5(.5)"), 0.25);
    ASSERT_EQ(calculator->Calculate(".7 + .3"), 1.0);
    ASSERT_EQ(calculator->Calculate("1.0 * (-.3)"), -0.3);
    ASSERT_EQ(calculator->Calculate("5.7 - (-0.3)"), 6.0);
}

TEST(CalculatorTests, Calculate_ShouldHandleFractions_WithCommas)
{
    auto calculator = make_unique<Calculator>();

    ASSERT_EQ(calculator->Calculate(",5(,5)"), 0.25);
    ASSERT_EQ(calculator->Calculate(",7 + ,3"), 1.0);
    ASSERT_EQ(calculator->Calculate("1,0 * (-,3)"), -0.3);
    ASSERT_EQ(calculator->Calculate("5,7 - (-0,3)"), 6.0);
}
