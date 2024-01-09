#include "gtest/gtest.h"
#include "tokenizer/Tokenizer.h"

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

TEST(TokenizerTests, ShouldTokenizeNumber_WithTrailingSeparator)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize("123.");

    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).type, ETokenType::NUMBER);
    EXPECT_EQ(tokenizer->getTokenAt(0).numberValue, 123.0);
}

TEST(TokenizerTests, ShouldTokenizeNumber_WithLeadingSeparator)
{
    auto tokenizer = make_unique<Tokenizer>();

    tokenizer->tokenize(".456");

    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).type, ETokenType::NUMBER);
    EXPECT_EQ(tokenizer->getTokenAt(0).numberValue, 0.456);
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
