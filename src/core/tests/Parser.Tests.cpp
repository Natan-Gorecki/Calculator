#include "gtest/gtest.h"
#include "Parser.h"

TEST(ParserTests, Parse_ShouldThrowException_ForMultipliedChars)
{
	Parser parser;

	EXPECT_THROW(parser.Parse(std::string("++2").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("2 ++ 5 - 6").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("2 / +5").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("-2 * (4 + -5)").c_str()), const char*);
}

TEST(ParserTests, Parse_ShouldThrowException_ForInvalidCharAtTheBeginning)
{
	Parser parser;

	EXPECT_THROW(parser.Parse(std::string("*2").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("/5 + 4").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("2 + (*6 - 4)").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("1/2 + (/4 + -5)").c_str()), const char*);
}

TEST(ParserTests, Parse_ShouldThrowException_ForInvalidCharAtTheEnd)
{
	Parser parser;

	EXPECT_THROW(parser.Parse(std::string("2*").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("2   -  ").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("2++").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("1/2 + (4 + 5+)").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("1/2 + (4 + )").c_str()), const char*);
}

TEST(ParserTests, Parse_ShouldThrowException_ForInvalidNumberOfDotsOrCommas)
{
	Parser parser;

	EXPECT_THROW(parser.Parse(std::string("2 + 5.. - 5").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("2 + 5,, - 5").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("2 - 6..").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("2 - 6,,").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("2.6. * 5").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("2,6, * 5").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string(".").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string(",").c_str()), const char*);
}

TEST(ParserTests, Parse_ShouldThrowException_ForInvalidBrackets)
{
	Parser parser;

	EXPECT_THROW(parser.Parse(std::string("( 2 + ( 4 - 5 )").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string(" ) ").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("(2+5) + 4( - 5").c_str()), const char*);
}

TEST(ParserTests, Parse_ShouldThrowException_ForEmptyEquation)
{
	Parser parser;

	EXPECT_THROW(parser.Parse(std::string("").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("  ").c_str()), const char*);
}

TEST(ParserTests, Parse_ShouldThrowException_ForEmptyBrackets)
{
	Parser parser;

	EXPECT_THROW(parser.Parse(std::string("2 + () - 4").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("4 - (  )   ").c_str()), const char*);
	EXPECT_THROW(parser.Parse(std::string("( )").c_str()), const char*);
}
