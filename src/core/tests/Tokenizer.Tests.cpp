#include "gtest/gtest.h"
#include "tokenizer/Tokenizer.h"
#include "CalculatorException.h"

using namespace std;

TEST(TokenizerTests, ShouldTokenizeString)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("sin30");

    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).tokenType, ETokenType::STRING);
    EXPECT_STREQ(tokenizer->getTokenAt(0).stringValue.c_str(), "sin30");
}

TEST(TokenizerTests, ShouldTokenizeNumber_WithDot)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("123.456");

    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).tokenType, ETokenType::NUMBER);
    EXPECT_STREQ(tokenizer->getTokenAt(0).stringValue.c_str(), "123.456");
    EXPECT_EQ(tokenizer->getTokenAt(0).numberValue, 123.456);
}

TEST(TokenizerTests, ShouldTokenizeNumber_WithComma)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("123,456");

    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).tokenType, ETokenType::NUMBER);
    EXPECT_STREQ(tokenizer->getTokenAt(0).stringValue.c_str(), "123,456");
    EXPECT_EQ(tokenizer->getTokenAt(0).numberValue, 123.456);
}

TEST(TokenizerTests, ShouldTokenizeCharacter)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("+");

    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).tokenType, ETokenType::CHAR);
    EXPECT_STREQ(tokenizer->getTokenAt(0).stringValue.c_str(), "+");
    EXPECT_EQ(tokenizer->getTokenAt(0).characterValue, '+');
}

TEST(TokenizerTests, ShouldTrimExpression)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("   sin30   ");

    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).tokenType, ETokenType::STRING);
    EXPECT_STREQ(tokenizer->getTokenAt(0).stringValue.c_str(), "sin30");
}

TEST(TokenizerTests, ShouldHandleManyTokens)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("sin30 sin60 sin90");

    EXPECT_EQ(tokenizer->getTokenCount(), 3);
    EXPECT_EQ(tokenizer->getTokenAt(0).tokenType, ETokenType::STRING);
    EXPECT_STREQ(tokenizer->getTokenAt(0).stringValue.c_str(), "sin30");
    EXPECT_EQ(tokenizer->getTokenAt(1).tokenType, ETokenType::STRING);
    EXPECT_STREQ(tokenizer->getTokenAt(1).stringValue.c_str(), "sin60");
    EXPECT_EQ(tokenizer->getTokenAt(2).tokenType, ETokenType::STRING);
    EXPECT_STREQ(tokenizer->getTokenAt(2).stringValue.c_str(), "sin90");
}

TEST(TokenizerTests, ShouldThrowException_ForUnexpectedToken)
{
    auto tokenizer = make_unique<Tokenizer>();

    EXPECT_THROW({
        tokenizer->tokenize("+?");
    }, CalculatorException);

    try
    {
        tokenizer->tokenize("+?");
    }
    catch (const CalculatorException& ex)
    {
        EXPECT_STREQ(ex.getExpression(), "+?");
        EXPECT_EQ(ex.getPosition(), 1);
    }
}

TEST(TokenizerTests, ShouldThrowException_ForDuplicatedSeparators)
{
    auto tokenizer = make_unique<Tokenizer>();

    EXPECT_THROW({
        tokenizer->tokenize("1,1,1");
    }, CalculatorException);

    try
    {
        tokenizer->tokenize("1,1,1");
    }
    catch (const CalculatorException& ex)
    {
        EXPECT_STREQ(ex.getExpression(), "1,1,1");
        EXPECT_EQ(ex.getPosition(), 3);
    }
}

TEST(TokenizerTests, ShouldThrowException_ForMissingDecimalPart)
{
    auto tokenizer = make_unique<Tokenizer>();

    EXPECT_THROW({
        tokenizer->tokenize("1,");
    }, CalculatorException);

    try
    {
        tokenizer->tokenize("1,");
    }
    catch (const CalculatorException& ex)
    {
        EXPECT_STREQ(ex.getExpression(), "1,");
        EXPECT_EQ(ex.getPosition(), 1);
    }
}