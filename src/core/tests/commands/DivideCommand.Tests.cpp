#include "gtest/gtest.h"
#include "commands/DivideCommand.h"
#include "commands/NumberCommand.h"

using namespace std;

TEST(DivideCommandTests, ShouldDivideCommands)
{
    auto command = make_unique<DivideCommand>(make_unique<NumberCommand>(1), make_unique<NumberCommand>(4));

    EXPECT_EQ(command->Execute(), 0.25);
}

TEST(DivideCommandTests, ShouldThrowException_WhenDivisorIsZero)
{
    auto command = make_unique<DivideCommand>(make_unique<NumberCommand>(1), make_unique<NumberCommand>(0));

    EXPECT_THROW({
        command->Execute();
    }, CommandException);
}
