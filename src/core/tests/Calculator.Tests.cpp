#include <functional>
#include "Calculator.h"
#include "gtest/gtest.h"

using namespace std;

class CalculatorTests : public ::testing::TestWithParam<EInterpreterType>
{
protected:
    unique_ptr<Calculator> createCalculator()
    {
        auto interpreterType = GetParam();
        return make_unique<Calculator>(interpreterType);
    }
};

INSTANTIATE_TEST_CASE_P(Undefined, CalculatorTests, ::testing::Values(
    EInterpreterType::UNDEFINED
));
INSTANTIATE_TEST_CASE_P(ShuntingYard, CalculatorTests, ::testing::Values(
    EInterpreterType::SHUNTING_YARD
));
INSTANTIATE_TEST_CASE_P(Recursive, CalculatorTests, ::testing::Values(
    EInterpreterType::RECURSIVE
));

TEST_P(CalculatorTests, ShouldHandleAddition)
{
    auto calculator = createCalculator();
    
    ASSERT_EQ(calculator->calculate("2 + 2"), 4.0);
    ASSERT_EQ(calculator->calculate("2 + 4 + 8"), 14.0);
    ASSERT_EQ(calculator->calculate("2 + (-2) + 5"), 5.0);
    ASSERT_EQ(calculator->calculate("-2 + 2"), 0.0);
    ASSERT_EQ(calculator->calculate("-2.5 + 2"), -0.5);
    ASSERT_EQ(calculator->calculate("-2,5 + 2.5"), 0.0);
}

TEST_P(CalculatorTests, ShouldHandleSubstraction)
{
    auto calculator = createCalculator();

    ASSERT_EQ(calculator->calculate(" 2- 7"), -5.0);
    ASSERT_EQ(calculator->calculate("-2 - 7 -5"), -14.0);
    ASSERT_EQ(calculator->calculate("-2 - (-7)"), 5.0);
    ASSERT_EQ(calculator->calculate(" 0.5 - 7,2"), -6.7);
}

TEST_P(CalculatorTests, ShouldHandleMultiplication)
{
    auto calculator = createCalculator();

    ASSERT_EQ(calculator->calculate(" 2 * 4"), 8.0);
    ASSERT_EQ(calculator->calculate("2 * (-5)"), -10.0);
    ASSERT_EQ(calculator->calculate("1/2 * (-1/2)"), -0.25);
    ASSERT_EQ(calculator->calculate(" 2 * 4 * (1/2)"), 4.0);
}

TEST_P(CalculatorTests, ShouldHandleDivision)
{
    auto calculator = createCalculator();

    ASSERT_EQ(calculator->calculate("16 / 2 / 5"), 1.6);
    ASSERT_EQ(calculator->calculate("16 / (-2) / 5"), -1.6);
    ASSERT_EQ(calculator->calculate("1/2 / (-1/2)"), -1.0);
    ASSERT_EQ(calculator->calculate(" 2 / 4 / (1/2)"), 1.0);
}

TEST_P(CalculatorTests, ShouldHandleBrackets)
{
    auto calculator = createCalculator();

    ASSERT_EQ(calculator->calculate("((((2))))"), 2.0);
    ASSERT_EQ(calculator->calculate("(((2.5)(-4.4))-2)"), -13.0);
    ASSERT_EQ(calculator->calculate("(2 + 5) * 2"), 14.0);
    ASSERT_EQ(calculator->calculate("(2 * 5 - 2) * (4.5 - 2 / 8)"), 34.0);
}

TEST_P(CalculatorTests, ShouldHandleMultiplication_WhenCharacterIsHidden)
{
    auto calculator = createCalculator();

    ASSERT_EQ(calculator->calculate("2(5-7)"), -4.0);
    ASSERT_EQ(calculator->calculate("(5-7)2"), -4.0);
    ASSERT_EQ(calculator->calculate("(3-5)(5-3)"), -4.0);
    ASSERT_EQ(calculator->calculate("(2 + 5) * 2(2+7)"), 126.0);
    ASSERT_EQ(calculator->calculate("-6(2(2))"), -24.0);
}

TEST_P(CalculatorTests, ShouldHandleCharacterAtTheBeginning)
{
    auto calculator = createCalculator();

    ASSERT_EQ(calculator->calculate("+7"), 7.0);
    ASSERT_EQ(calculator->calculate("-2 + (-7)"), -9.0);
}

TEST_P(CalculatorTests, ShouldHandleFractions_WithDots)
{
    auto calculator = createCalculator();

    // TODO ASSERT_EQ(calculator->calculate(".5(.5)"), 0.25);
    // TODO ASSERT_EQ(calculator->calculate(".7 + .3"), 1.0);
    // TODO ASSERT_EQ(calculator->calculate("1.0 * (-.3)"), -0.3);
    ASSERT_EQ(calculator->calculate("5.7 - (-0.3)"), 6.0);
}

TEST_P(CalculatorTests, ShouldHandleFractions_WithCommas)
{
    auto calculator = createCalculator();

    // TODO ASSERT_EQ(calculator->calculate(",5(,5)"), 0.25);
    // TODO ASSERT_EQ(calculator->calculate(",7 + ,3"), 1.0);
    // TODO ASSERT_EQ(calculator->calculate("1,0 * (-,3)"), -0.3);
    ASSERT_EQ(calculator->calculate("5,7 - (-0,3)"), 6.0);
}
