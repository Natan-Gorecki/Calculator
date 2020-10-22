#include "Commands.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace CalculatorTests
{
	TEST_CLASS(Commands_Tests)
	{
	public:

		TEST_METHOD(NumberCommand_ExecuteMethod_ShouldBeEqual)
		{
			C_NumberCommand number(13.456);

			Assert::AreEqual(number.Execute(), 13.456);
		}


		TEST_METHOD(AddCommand_ExecuteMethod_ShouldBeEqual)
		{
			C_NumberCommand* left = new C_NumberCommand(-13);
			C_NumberCommand* right = new C_NumberCommand(36);
			C_AddCommand command(left, right);
			

			Assert::AreEqual(command.Execute(), 23.0);
		}


		TEST_METHOD(SubtractCommand_ExecuteMethod_ShouldBeEqual)
		{
			C_NumberCommand* left = new C_NumberCommand(-13);
			C_NumberCommand* right = new C_NumberCommand(36);
			C_SubtractCommand command(left, right);


			Assert::AreEqual(command.Execute(), -49.0);
		}


		TEST_METHOD(MultiplyCommand_ExecuteMethod_ShouldBeEqual)
		{
			C_NumberCommand* left = new C_NumberCommand(-13);
			C_NumberCommand* right = new C_NumberCommand(36);
			C_MultiplyCommand command(left, right);


			Assert::AreEqual(command.Execute(), -468.0);
		}


		TEST_METHOD(DivideCommand_ExecuteMethod_ShouldBeEqual)
		{
			C_NumberCommand* left = new C_NumberCommand(1);
			C_NumberCommand* right = new C_NumberCommand(4);
			C_DivideCommand command(left, right);


			Assert::AreEqual(command.Execute(), 0.25);
		}

		
		TEST_METHOD(DivideCommand_ExecuteMethod_ExpectedException)
		{
			C_NumberCommand* left = new C_NumberCommand(56);
			C_NumberCommand* right = new C_NumberCommand(0);
			C_DivideCommand command(left, right);

			
			auto method = [&command] { return command.Execute(); };
			Assert::ExpectException<const char*>(method, L"Division by 0");
		}
	};
}