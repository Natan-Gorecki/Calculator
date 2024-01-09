#include "gtest/gtest.h"
#include "syntax_analyzer/SyntaxAnalyzer.h"

using namespace std;

TEST(SyntaxAnalyzerTests, ShouldHandleSignOfNumber)
{
    auto tokenizer = make_unique<Tokenizer>();
    tokenizer->tokenize("-1+(+4)");
    auto analyzer = make_unique<SyntaxAnalyzer>();

    analyzer->analyze(tokenizer.get());

    EXPECT_EQ(tokenizer->getTokenCount(), 5);
    EXPECT_EQ(tokenizer->getTokenAt(0).numberValue, -1);
    EXPECT_EQ(tokenizer->getTokenAt(3).numberValue, 4);
}

TEST(SyntaxAnalyzerTests, ShouldHandleHiddenMultiplication)
{
    auto tokenizer = make_unique<Tokenizer>();
    tokenizer->tokenize("1(2-3)(4-5)6");
    auto analyzer = make_unique<SyntaxAnalyzer>();

    analyzer->analyze(tokenizer.get());

    EXPECT_EQ(tokenizer->getTokenCount(), 15);
    EXPECT_EQ(tokenizer->getTokenAt(1).charValue, '*');
    EXPECT_EQ(tokenizer->getTokenAt(7).charValue, '*');
    EXPECT_EQ(tokenizer->getTokenAt(13).charValue, '*');
}

TEST(SyntaxAnalyzerTests, ShouldHandleEmptyBrackets)
{
    auto tokenizer = make_unique<Tokenizer>();
    tokenizer->tokenize("((()))()3");
    auto analyzer = make_unique<SyntaxAnalyzer>();

    analyzer->analyze(tokenizer.get());

    EXPECT_EQ(tokenizer->getTokenCount(), 1);
    EXPECT_EQ(tokenizer->getTokenAt(0).numberValue, 3);
}
