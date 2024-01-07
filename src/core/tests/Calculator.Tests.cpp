#include <functional>
#include "gtest/gtest.h"
#include "Calculator.h"
#include "ExpressionException.h"

using namespace std;

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
    EInterpreterType convertInterpreterType(string typeString) const
    {
        if (typeString == "ShuntingYard")
        {
            return EInterpreterType::SHUNTING_YARD;
        }
        if (typeString == "Recursive")
        {
            return EInterpreterType::RECURSIVE;
        }
        return EInterpreterType::UNDEFINED;
    }
};

INSTANTIATE_TEST_CASE_P(_, CalculatorTests, ::testing::Values(
    "Undefined",
    "ShuntingYard",
    "Recursive"
));

#pragma region Operations
TEST_P(CalculatorTests, ShouldHandleAddition)
{
    ASSERT_EQ(mCalculator->calculate("2 + 2"), 4.0);
    ASSERT_EQ(mCalculator->calculate("2 + 4 + 8"), 14.0);
    ASSERT_EQ(mCalculator->calculate("2 + (-2) + 5"), 5.0);
    ASSERT_EQ(mCalculator->calculate("-2 + 2"), 0.0);
    ASSERT_EQ(mCalculator->calculate("-2.5 + 2"), -0.5);
    ASSERT_EQ(mCalculator->calculate("-2,5 + 2.5"), 0.0);
}

TEST_P(CalculatorTests, ShouldHandleSubstraction)
{
    ASSERT_EQ(mCalculator->calculate(" 2- 7"), -5.0);
    ASSERT_EQ(mCalculator->calculate("-2 - 7 -5"), -14.0);
    ASSERT_EQ(mCalculator->calculate("-2 - (-7)"), 5.0);
    ASSERT_EQ(mCalculator->calculate(" 0.5 - 7,2"), -6.7);
}

TEST_P(CalculatorTests, ShouldHandleMultiplication)
{
    ASSERT_EQ(mCalculator->calculate(" 2 * 4"), 8.0);
    ASSERT_EQ(mCalculator->calculate("2 * (-5)"), -10.0);
    ASSERT_EQ(mCalculator->calculate("1/2 * (-1/2)"), -0.25);
    ASSERT_EQ(mCalculator->calculate(" 2 * 4 * (1/2)"), 4.0);
}

TEST_P(CalculatorTests, ShouldHandleDivision)
{
    ASSERT_EQ(mCalculator->calculate("16 / 2 / 5"), 1.6);
    ASSERT_EQ(mCalculator->calculate("16 / (-2) / 5"), -1.6);
    ASSERT_EQ(mCalculator->calculate("1/2 / (-1/2)"), -1.0);
    ASSERT_EQ(mCalculator->calculate(" 2 / 4 / (1/2)"), 1.0);
}

TEST_P(CalculatorTests, ShouldHandleBrackets)
{
    ASSERT_EQ(mCalculator->calculate("((((2))))"), 2.0);
    ASSERT_EQ(mCalculator->calculate("(((2.5)(-4.4))-2)"), -13.0);
    ASSERT_EQ(mCalculator->calculate("(2 + 5) * 2"), 14.0);
    ASSERT_EQ(mCalculator->calculate("(2 * 5 - 2) * (4.5 - 2 / 8)"), 34.0);
}

TEST_P(CalculatorTests, ShouldHandleMultiplication_WhenCharacterIsHidden)
{
    ASSERT_EQ(mCalculator->calculate("2(5-7)"), -4.0);
    ASSERT_EQ(mCalculator->calculate("(5-7)2"), -4.0);
    ASSERT_EQ(mCalculator->calculate("(3-5)(5-3)"), -4.0);
    ASSERT_EQ(mCalculator->calculate("(2 + 5) * 2(2+7)"), 126.0);
    ASSERT_EQ(mCalculator->calculate("-6(2(2))"), -24.0);
}

TEST_P(CalculatorTests, ShouldHandleCharacterAtTheBeginning)
{
    ASSERT_EQ(mCalculator->calculate("+7"), 7.0);
    ASSERT_EQ(mCalculator->calculate("-2 + (-7)"), -9.0);
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
#pragma endregion

#pragma region Exceptions
#define EXPECT_EXPRESSION_EXCEPTION(expression, position)\
try\
{\
    mCalculator->calculate(expression);\
    FAIL() << "Expected exception.";\
}\
catch (const ExpressionException& ex)\
{\
    EXPECT_STREQ(ex.getExpression(), expression);\
    EXPECT_EQ(ex.getPosition(), position);\
}

TEST_P(CalculatorTests, ShouldThrowException_ForUnexpectedToken)
{
    EXPECT_EXPRESSION_EXCEPTION("+?", 1);
}

TEST_P(CalculatorTests, ShouldThrowException_ForInvalidSeparatorUsage)
{
    EXPECT_EXPRESSION_EXCEPTION(",", 0);
    EXPECT_EXPRESSION_EXCEPTION(".", 0);
    EXPECT_EXPRESSION_EXCEPTION(".2", 0);
    EXPECT_EXPRESSION_EXCEPTION("2..", 2);
    EXPECT_EXPRESSION_EXCEPTION("2 + 5.. - 5", 4);
    EXPECT_EXPRESSION_EXCEPTION("2 - 6..", 4);
    EXPECT_EXPRESSION_EXCEPTION("2.6. * 5", 3);
}

TEST_P(CalculatorTests, ShouldThrowException_ForDuplicatedSeparators)
{
    EXPECT_EXPRESSION_EXCEPTION("1,1,1", 3);
    EXPECT_EXPRESSION_EXCEPTION("1.1.1", 3);
}

TEST_P(CalculatorTests, ShouldThrowException_ForMissingDecimalPart)
{
    EXPECT_EXPRESSION_EXCEPTION("1,", 1);
    EXPECT_EXPRESSION_EXCEPTION("1.", 1);
}

TEST_P(CalculatorTests, ShouldThrowException_ForDuplicatedOperators)
{
    EXPECT_EXPRESSION_EXCEPTION("++2", 1);
    EXPECT_EXPRESSION_EXCEPTION("2 ++ 5 - 6", 2);
    EXPECT_EXPRESSION_EXCEPTION("2 / +5", 2);
    EXPECT_EXPRESSION_EXCEPTION("-2 * (4 + -5)", 6);
}

TEST_P(CalculatorTests, ShouldThrowException_ForInvalidCharAtStart)
{
    EXPECT_EXPRESSION_EXCEPTION("*2", 0);
    EXPECT_EXPRESSION_EXCEPTION("/5 + 4", 0);
    EXPECT_EXPRESSION_EXCEPTION("2 + (*6 - 4)", 3);
    EXPECT_EXPRESSION_EXCEPTION("1/2 + (/4 + -5)", 5);
}

TEST_P(CalculatorTests, ShouldThrowException_ForInvalidCharAtEnd)
{
    EXPECT_EXPRESSION_EXCEPTION("2*", 1);
    EXPECT_EXPRESSION_EXCEPTION("2   -  ", 1);
    EXPECT_EXPRESSION_EXCEPTION("2++", 2);
    EXPECT_EXPRESSION_EXCEPTION("1/2 + (4 + 5+)", 8);
    EXPECT_EXPRESSION_EXCEPTION("1/2 + (4 + )", 6);
}

TEST_P(CalculatorTests, ShouldThrowException_ForEmptyExpression)
{
    EXPECT_EXPRESSION_EXCEPTION("", 0);
    EXPECT_EXPRESSION_EXCEPTION("   ", 0);
    EXPECT_EXPRESSION_EXCEPTION("()", 0);
}

TEST_P(CalculatorTests, ShouldThrowException_ForEmptyBrackets)
{
    EXPECT_EXPRESSION_EXCEPTION("2 + () - 4", 2);
    EXPECT_EXPRESSION_EXCEPTION("4 - (  )   ", 2);
}

TEST_P(CalculatorTests, ShouldThrowException_ForNotClosedBrackets)
{
    EXPECT_EXPRESSION_EXCEPTION("( 2 + ( 4 - 5 )", 0);
    EXPECT_EXPRESSION_EXCEPTION(" ) ", 0);
    EXPECT_EXPRESSION_EXCEPTION("(2+5) + 4( - 5", 7);
}
#pragma endregion
