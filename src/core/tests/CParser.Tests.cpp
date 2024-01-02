#include "C_Parser.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace CalculatorTests
{
	TEST_CLASS(C_Parser_Tests)
	{
	public:

		TEST_METHOD(ParseMethod_MultipliedChars_ExpectedException)
		{
			C_Parser parser;


			auto method1 = [&parser] { parser.Parse(std::string("++2").c_str()); };
			auto method2 = [&parser] { parser.Parse(std::string("2 ++ 5 - 6").c_str()); };
			auto method3 = [&parser] { parser.Parse(std::string("2 / +5").c_str()); };
			auto method4 = [&parser] { parser.Parse(std::string("-2 * (4 + -5)").c_str()); };


			Assert::ExpectException<const char*>(method1);
			Assert::ExpectException<const char*>(method2);
			Assert::ExpectException<const char*>(method3);
			Assert::ExpectException<const char*>(method4);
		}


		TEST_METHOD(ParseMethod_InvalidCharacterAtTheBeginning_ExpectedException)
		{
			C_Parser parser;


			auto method1 = [&parser] { parser.Parse(std::string("*2").c_str()); };
			auto method2 = [&parser] { parser.Parse(std::string("/5 + 4").c_str()); };
			auto method3 = [&parser] { parser.Parse(std::string("2 + (*6 - 4)").c_str()); };
			auto method4 = [&parser] { parser.Parse(std::string("1/2 + (/4 + -5)").c_str()); };


			Assert::ExpectException<const char*>(method1);
			Assert::ExpectException<const char*>(method2);
			Assert::ExpectException<const char*>(method3);
			Assert::ExpectException<const char*>(method4);
		}

		
		TEST_METHOD(ParseMethod_OperationCharacterAtTheEnd_ExpectedException)
		{
			C_Parser parser;


			auto method1 = [&parser] { parser.Parse(std::string("2*").c_str()); };
			auto method2 = [&parser] { parser.Parse(std::string("2   -  ").c_str()); };
			auto method3 = [&parser] { parser.Parse(std::string("2++").c_str()); };
			auto method4 = [&parser] { parser.Parse(std::string("1/2 + (4 + 5+)").c_str()); };
			auto method5 = [&parser] { parser.Parse(std::string("1/2 + (4 + )").c_str()); };


			Assert::ExpectException<const char*>(method1);
			Assert::ExpectException<const char*>(method2);
			Assert::ExpectException<const char*>(method3);
			Assert::ExpectException<const char*>(method4);
			Assert::ExpectException<const char*>(method5);
		}


		TEST_METHOD(ParseMethod_InvalidNumberOfDotsOrCommas_ExpectedException)
		{
			C_Parser parser;


			auto method1 = [&parser] { parser.Parse(std::string("2 + 5.. - 5").c_str()); };
			auto method2 = [&parser] { parser.Parse(std::string("2 + 5,, - 5").c_str()); };
			auto method3 = [&parser] { parser.Parse(std::string("2 - 6..").c_str()); };
			auto method4 = [&parser] { parser.Parse(std::string("2 - 6,,").c_str()); };
			auto method5 = [&parser] { parser.Parse(std::string("2.6. * 5").c_str()); };
			auto method6 = [&parser] { parser.Parse(std::string("2,6, * 5").c_str()); };
			auto method7 = [&parser] { parser.Parse(std::string(".").c_str()); };
			auto method8 = [&parser] { parser.Parse(std::string(",").c_str()); };


			Assert::ExpectException<const char*>(method1);
			Assert::ExpectException<const char*>(method2);
			Assert::ExpectException<const char*>(method3);
			Assert::ExpectException<const char*>(method4);
			Assert::ExpectException<const char*>(method5);
			Assert::ExpectException<const char*>(method6);
			Assert::ExpectException<const char*>(method7);
			Assert::ExpectException<const char*>(method8);
		}


		TEST_METHOD(ParseMethod_InvalidParentheses_ExpectedException)
		{
			C_Parser parser;


			auto method1 = [&parser] { parser.Parse(std::string("( 2 + ( 4 - 5 )").c_str()); };
			auto method2 = [&parser] { parser.Parse(std::string(" ) ").c_str()); };
			auto method3 = [&parser] { parser.Parse(std::string("(2+5) + 4( - 5").c_str()); };


			Assert::ExpectException<const char*>(method1);
			Assert::ExpectException<const char*>(method2);
			Assert::ExpectException<const char*>(method3);
		}


		TEST_METHOD(ParseMethod_EmptyEquation_ExpectedException)
		{
			C_Parser parser;


			auto method1 = [&parser] { parser.Parse(std::string("").c_str()); };
			auto method2 = [&parser] { parser.Parse(std::string("  ").c_str()); };


			Assert::ExpectException<const char*>(method1);
			Assert::ExpectException<const char*>(method2);
		}

		
		TEST_METHOD(ParseMethod_EmptyParentheses_ExpectedException)
		{
			C_Parser parser;


			auto method1 = [&parser] { parser.Parse(std::string("2 + () - 4").c_str()); };
			auto method2 = [&parser] { parser.Parse(std::string("4 - (  )   ").c_str()); };
			auto method3 = [&parser] { parser.Parse(std::string("( )").c_str()); };


			Assert::ExpectException<const char*>(method1);
			Assert::ExpectException<const char*>(method2);
			Assert::ExpectException<const char*>(method3);
		}
	};
}
