#include "gtest/gtest.h"
#include "Commands.h"

TEST(CommandsTests, NumberCommandTests)
{
	NumberCommand number(13.456);

	ASSERT_EQ(number.Execute(), 13.456);
}

TEST(CommandsTests, AddCommandTests)
{
	NumberCommand* left = new NumberCommand(-13);
	NumberCommand* right = new NumberCommand(36);
	AddCommand command(left, right);


	ASSERT_EQ(command.Execute(), 23.0);
}

TEST(CommandsTests, SubtractCommandTests)
{
	NumberCommand* left = new NumberCommand(-13);
	NumberCommand* right = new NumberCommand(36);
	SubtractCommand command(left, right);


	ASSERT_EQ(command.Execute(), -49.0);
}

TEST(CommandsTests, MultiplyCommandTests)
{
	NumberCommand* left = new NumberCommand(-13);
	NumberCommand* right = new NumberCommand(36);
	MultiplyCommand command(left, right);


	ASSERT_EQ(command.Execute(), -468.0);
}

TEST(CommandsTests, DivideCommandTests)
{
	NumberCommand* left = new NumberCommand(1);
	NumberCommand* right = new NumberCommand(4);
	DivideCommand command(left, right);


	ASSERT_EQ(command.Execute(), 0.25);
}

TEST(CommandsTests, DivideCommand_ShouldHandleInvalidDivisor)
{
	NumberCommand* left = new NumberCommand(56);
	NumberCommand* right = new NumberCommand(0);
	DivideCommand command(left, right);


	EXPECT_THROW(command.Execute(), const char*);
}
