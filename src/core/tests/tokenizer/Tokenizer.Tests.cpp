#include "gtest/gtest.h"
#include "tokenizer/Tokenizer.h"
#include "tokenizer/TokenizerException.h"

using namespace std;

TEST(TokenizerTests, ShouldTokenizeOperator)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("+");
    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).type, ETokenType::OPERATOR);
    EXPECT_EQ(tokenizer->getTokenAt(0).charValue, '+');
}

TEST(TokenizerTests, ShouldTokenizeNumber_WithDot)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("123.456");

    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).type, ETokenType::NUMBER);
    EXPECT_EQ(tokenizer->getTokenAt(0).numberValue, 123.456);
}

TEST(TokenizerTests, ShouldTokenizeNumber_WithComma)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("123,456");

    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).type, ETokenType::NUMBER);
    EXPECT_EQ(tokenizer->getTokenAt(0).numberValue, 123.456);
}

TEST(TokenizerTests, ShouldTokenizeSeparator)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("(");

    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).type, ETokenType::SEPARATOR);
    EXPECT_EQ(tokenizer->getTokenAt(0).charValue, '(');
}

TEST(TokenizerTests, ShouldTrimExpression)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("   123.456   ");

    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).type, ETokenType::NUMBER);
    EXPECT_EQ(tokenizer->getTokenAt(0).numberValue, 123.456);
}

TEST(TokenizerTests, ShouldHandleManyTokens)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("2 + 4");

    EXPECT_EQ(tokenizer->getTokenCount(), 3);
    EXPECT_EQ(tokenizer->getTokenAt(0).type, ETokenType::NUMBER);
    EXPECT_EQ(tokenizer->getTokenAt(0).numberValue, 2);
    EXPECT_EQ(tokenizer->getTokenAt(1).type, ETokenType::OPERATOR);
    EXPECT_EQ(tokenizer->getTokenAt(1).charValue, '+');
    EXPECT_EQ(tokenizer->getTokenAt(2).type, ETokenType::NUMBER);
    EXPECT_EQ(tokenizer->getTokenAt(2).numberValue, 4);
}

TEST(TokenizerTests, ShouldThrowException_ForUnexpectedToken)
{
    auto tokenizer = make_unique<Tokenizer>();

    EXPECT_THROW({
        tokenizer->tokenize("+?");
    }, TokenizerException);

    try
    {
        tokenizer->tokenize("+?");
    }
    catch (const TokenizerException& ex)
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
    }, TokenizerException);

    try
    {
        tokenizer->tokenize("1,1,1");
    }
    catch (const TokenizerException& ex)
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
    }, TokenizerException);

    try
    {
        tokenizer->tokenize("1,");
    }
    catch (const TokenizerException& ex)
    {
        EXPECT_STREQ(ex.getExpression(), "1,");
        EXPECT_EQ(ex.getPosition(), 1);
    }
}
