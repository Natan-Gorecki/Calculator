#include <functional>
#include "gtest/gtest.h"
#include "Calculator.h"
#include "ExpressionException.h"

using namespace std;
using namespace CalculatorCore;

class CalculatorTests : public ::testing::TestWithParam<string>
{
protected:
    std::unique_ptr<Calculator> mCalculator;

    void SetUp() override
    {
        mCalculator = createCalculator();
    }

    unique_ptr<Calculator> createCalculator()
    {
        auto interpreterType = convertInterpreterType(GetParam());
        return make_unique<Calculator>(interpreterType);
    }

private:
    EInterpreterType convertInterpreterType(const string& typeString) const
    {
        if (typeString == "Recursive")
        {
            return EInterpreterType::RECURSIVE;
        }
        return EInterpreterType::SHUNTING_YARD;
    }
};

INSTANTIATE_TEST_CASE_P(_, CalculatorTests, ::testing::Values(
    "ShuntingYard",
    "Recursive"
));

#pragma region Operations
TEST_P(CalculatorTests, ShouldHandleAddition)
{
    ASSERT_EQ(mCalculator->calculate("2 + 2").numericResult, 4.0);
    ASSERT_EQ(mCalculator->calculate("2 + 4 + 8").numericResult, 14.0);
    ASSERT_EQ(mCalculator->calculate("2 + (-2) + 5").numericResult, 5.0);
    ASSERT_EQ(mCalculator->calculate("-2 + 2").numericResult, 0.0);
    ASSERT_EQ(mCalculator->calculate("-2.5 + 2").numericResult, -0.5);
    ASSERT_EQ(mCalculator->calculate("-2.5 + 2.5").numericResult, 0.0);
}

TEST_P(CalculatorTests, ShouldHandleSubstraction)
{
    ASSERT_EQ(mCalculator->calculate(" 2- 7").numericResult, -5.0);
    ASSERT_EQ(mCalculator->calculate("-2 - 7 -5").numericResult, -14.0);
    ASSERT_EQ(mCalculator->calculate("-2 - (-7)").numericResult, 5.0);
    ASSERT_EQ(mCalculator->calculate(" 0.5 - 7.2").numericResult, -6.7);
}

TEST_P(CalculatorTests, ShouldHandleMultiplication)
{
    ASSERT_EQ(mCalculator->calculate(" 2 * 4").numericResult, 8.0);
    ASSERT_EQ(mCalculator->calculate("2 * (-5)").numericResult, -10.0);
    ASSERT_EQ(mCalculator->calculate("1/2 * (-1/2)").numericResult, -0.25);
    ASSERT_EQ(mCalculator->calculate(" 2 * 4 * (1/2)").numericResult, 4.0);
}

TEST_P(CalculatorTests, ShouldHandleMultiplication_WhenCharacterIsHidden)
{
    ASSERT_EQ(mCalculator->calculate("2(5-7)").numericResult, -4.0);
    ASSERT_EQ(mCalculator->calculate("(5-7)2").numericResult, -4.0);
    ASSERT_EQ(mCalculator->calculate("(3-5)(5-3)").numericResult, -4.0);
    ASSERT_EQ(mCalculator->calculate("(2 + 5) * 2(2+7)").numericResult, 126.0);
    ASSERT_EQ(mCalculator->calculate("-6(2(2))").numericResult, -24.0);
}

TEST_P(CalculatorTests, ShouldHandleDivision)
{
    ASSERT_EQ(mCalculator->calculate("16 / 2 / 5").numericResult, 1.6);
    ASSERT_EQ(mCalculator->calculate("16 / (-2) / 5").numericResult, -1.6);
    ASSERT_EQ(mCalculator->calculate("1/2 / (-1/2)").numericResult, -1.0);
    ASSERT_EQ(mCalculator->calculate(" 2 / 4 / (1/2)").numericResult, 1.0);
}

TEST_P(CalculatorTests, ShouldHandleBrackets)
{
    ASSERT_EQ(mCalculator->calculate("((((2))))").numericResult, 2.0);
    ASSERT_EQ(mCalculator->calculate("(((2.5)(-4.4))-2)").numericResult, -13.0);
    ASSERT_EQ(mCalculator->calculate("(2 + 5) * 2").numericResult, 14.0);
    ASSERT_EQ(mCalculator->calculate("(2 * 5 - 2) * (4.5 - 2 / 8)").numericResult, 34.0);
}

TEST_P(CalculatorTests, ShouldHandleSignOfNumber)
{
    ASSERT_EQ(mCalculator->calculate("+7").numericResult, 7.0);
    ASSERT_EQ(mCalculator->calculate("-2 + (-7)").numericResult, -9.0);
}

TEST_P(CalculatorTests, ShouldHandleFractions)
{
    auto calculator = createCalculator();

    ASSERT_EQ(calculator->calculate(".7 + .3").numericResult, 1);
    ASSERT_EQ(calculator->calculate("5. + 5.").numericResult, 10);
    ASSERT_EQ(calculator->calculate("1.0 * (-0.3)").numericResult, -0.3);
    ASSERT_EQ(calculator->calculate("5.7 - (-0.3)").numericResult, 6.0);
}
#pragma endregion

#pragma region Exceptions
#define EXPECT_CALCULATION_ERROR(expression, position)\
{\
    CalculatorCore::CalculationResult calculationResult = mCalculator->calculate(expression); \
    EXPECT_EQ(calculationResult.isSuccess, false); \
    EXPECT_EQ(calculationResult.numericResult, 0); \
    EXPECT_EQ(calculationResult.errorPosition, position); \
    EXPECT_STREQ(calculationResult.errorExpression, expression);\
}

TEST_P(CalculatorTests, ShouldCountPropertlyCharacters)
{
    EXPECT_CALCULATION_ERROR("((()))3-", 7);
    EXPECT_CALCULATION_ERROR("(2)(2-) ", 5);
    EXPECT_CALCULATION_ERROR("-1+(-2)-", 7);
}

TEST_P(CalculatorTests, ShouldThrowException_ForUnexpectedToken)
{
    EXPECT_CALCULATION_ERROR("+?", 1);
    EXPECT_CALCULATION_ERROR(",1", 0);
}

TEST_P(CalculatorTests, ShouldThrowException_ForInvalidSeparatorUsage)
{
    EXPECT_CALCULATION_ERROR(".", 0);
    EXPECT_CALCULATION_ERROR("..2", 1);
    EXPECT_CALCULATION_ERROR("2..", 2);
    EXPECT_CALCULATION_ERROR("2 + 5.. - 5", 6);
    EXPECT_CALCULATION_ERROR("2 - 6..", 6);
    EXPECT_CALCULATION_ERROR("2.6. * 5", 3);
}

TEST_P(CalculatorTests, ShouldThrowException_ForDuplicatedSeparators)
{
    EXPECT_CALCULATION_ERROR("1.1.1", 3);
}

TEST_P(CalculatorTests, ShouldThrowException_ForDuplicatedOperators)
{
    EXPECT_CALCULATION_ERROR("++2", 1);
    EXPECT_CALCULATION_ERROR("2 ++ 5 - 6", 3);
    EXPECT_CALCULATION_ERROR("2 / +5", 4);
    EXPECT_CALCULATION_ERROR("-2 * (4 + -5)", 10);
}

TEST_P(CalculatorTests, ShouldThrowException_ForInvalidCharAtStart)
{
    EXPECT_CALCULATION_ERROR("*2", 0);
    EXPECT_CALCULATION_ERROR("/5 + 4", 0);
    EXPECT_CALCULATION_ERROR("2 + (*6 - 4)", 5);
    EXPECT_CALCULATION_ERROR("1/2 + (/4 + -5)", 12);
}

TEST_P(CalculatorTests, ShouldThrowException_ForInvalidCharAtEnd)
{
    EXPECT_CALCULATION_ERROR("2*", 1);
    EXPECT_CALCULATION_ERROR("2   -  ", 4);
    EXPECT_CALCULATION_ERROR("2++", 2);
    EXPECT_CALCULATION_ERROR("1/2 + (4 + 5+)", 12);
    EXPECT_CALCULATION_ERROR("1/2 + (4 + )", 9);
}

TEST_P(CalculatorTests, ShouldThrowException_ForEmptyExpression)
{
    EXPECT_CALCULATION_ERROR("", 0);
    EXPECT_CALCULATION_ERROR("   ", 0);
    EXPECT_CALCULATION_ERROR("()", 0);
}

TEST_P(CalculatorTests, ShouldThrowException_ForSingleOperator)
{
    EXPECT_CALCULATION_ERROR("-", 0);
    EXPECT_CALCULATION_ERROR("+", 0);
    EXPECT_CALCULATION_ERROR("*", 0);
    EXPECT_CALCULATION_ERROR("/", 0);
}

TEST_P(CalculatorTests, ShouldThrowException_ForNotClosedBrackets)
{
    EXPECT_CALCULATION_ERROR("( 2 + ( 4 - 5 )", 0);
    EXPECT_CALCULATION_ERROR(" ) ", 1);
    EXPECT_CALCULATION_ERROR("(2+5) + 4 ( - 5", 10);
    EXPECT_CALCULATION_ERROR("2))(", 1);
}
#pragma endregion
