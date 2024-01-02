#include "C_Calculator.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace CalculatorTests
{
	TEST_CLASS(C_Calculator_Tests)
	{
	public:

		TEST_METHOD(CalculateMethod_Addition_ShouldBeEqual)
		{
			C_Calculator calculator;


			Assert::AreEqual(calculator.Calculate("2 + 2"), 4.0);
			Assert::AreEqual(calculator.Calculate("2 + 4 + 8"), 14.0);
			Assert::AreEqual(calculator.Calculate("2 + (-2) + 5"), 5.0);
			Assert::AreEqual(calculator.Calculate("-2 + 2"), 0.0);
			Assert::AreEqual(calculator.Calculate("-2.5 + 2"), -0.5);
			Assert::AreEqual(calculator.Calculate("-2,5 + 2.5"), 0.0);
		}


		TEST_METHOD(CalculateMethod_Substraction_ShouldBeEqual)
		{
			C_Calculator calculator;


			Assert::AreEqual(calculator.Calculate(" 2- 7"), -5.0);
			Assert::AreEqual(calculator.Calculate("-2 - 7 -5"), -14.0);
			Assert::AreEqual(calculator.Calculate("-2 - (-7)"), 5.0);
			Assert::AreEqual(calculator.Calculate(" 0.5 - 7,2"), -6.7);	
		}


		TEST_METHOD(CalculateMethod_Multiplication_ShouldBeEqual)
		{
			C_Calculator calculator;


			Assert::AreEqual(calculator.Calculate(" 2 * 4"), 8.0);
			Assert::AreEqual(calculator.Calculate("2 * (-5)"), -10.0);
			Assert::AreEqual(calculator.Calculate("1/2 * (-1/2)"), -0.25);
			Assert::AreEqual(calculator.Calculate(" 2 * 4 * (1/2)"), 4.0);
		}


		TEST_METHOD(CalculateMethod_Division_ShouldBeEqual)
		{
			C_Calculator calculator;


			Assert::AreEqual(calculator.Calculate("16 / 2 / 5"), 1.6);
			Assert::AreEqual(calculator.Calculate("16 / (-2) / 5"), -1.6);
			Assert::AreEqual(calculator.Calculate("1/2 / (-1/2)"), -1.0);
			Assert::AreEqual(calculator.Calculate(" 2 / 4 / (1/2)"), 1.0);
		}


		TEST_METHOD(CalculateMethod_Parentheses_ShouldBeEqual)
		{
			C_Calculator calculator;


			Assert::AreEqual(calculator.Calculate("((((2))))"), 2.0);
			Assert::AreEqual(calculator.Calculate("(((2.5)(-4.4))-2)"), -13.0);
			Assert::AreEqual(calculator.Calculate("(2 + 5) * 2"), 14.0);
			Assert::AreEqual(calculator.Calculate("(2 * 5 - 2) * (4.5 - 2 / 8)"), 34.0);
		}


		TEST_METHOD(CalculateMethod_DefaultMultiplication_ShouldBeEqual)
		{
			C_Calculator calculator;


			Assert::AreEqual(calculator.Calculate("2(5-7)"), -4.0);
			Assert::AreEqual(calculator.Calculate("(5-7)2"), -4.0);
			Assert::AreEqual(calculator.Calculate("(3-5)(5-3)"), -4.0);
			Assert::AreEqual(calculator.Calculate("(2 + 5) * 2(2+7)"), 126.0);
			Assert::AreEqual(calculator.Calculate("-6(2(2))"), -24.0);
		}


		TEST_METHOD(CalculateMethod_CharacterAtTheBeginning_ShouldBeEqual)
		{
			C_Calculator calculator;


			Assert::AreEqual(calculator.Calculate("+7"), 7.0);
			Assert::AreEqual(calculator.Calculate("-2 + (-7)"), -9.0);
		}


		TEST_METHOD(CalculateMethod_DottedFractions_ShouldBeEqual)
		{
			C_Calculator calculator;


			Assert::AreEqual(calculator.Calculate(".5(.5)"), 0.25);
			Assert::AreEqual(calculator.Calculate(".7 + .3"), 1.0);
			Assert::AreEqual(calculator.Calculate("1.0 * (-.3)"), -0.3);
			Assert::AreEqual(calculator.Calculate("5.7 - (-0.3)"), 6.0);
		}


		TEST_METHOD(CalculateMethod_FractionsWithComma_ShouldBeEqual)
		{
			C_Calculator calculator;


			Assert::AreEqual(calculator.Calculate(",5(,5)"), 0.25);
			Assert::AreEqual(calculator.Calculate(",7 + ,3"), 1.0);
			Assert::AreEqual(calculator.Calculate("1,0 * (-,3)"), -0.3);
			Assert::AreEqual(calculator.Calculate("5,7 - (-0,3)"), 6.0);
		}
	};
}