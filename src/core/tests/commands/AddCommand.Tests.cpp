#include "gtest/gtest.h"
#include "commands/AddCommand.h"
#include "commands/NumberCommand.h"

using namespace std;

TEST(AddCommandTests, ShouldAddCommands)
{
    auto command = make_unique<AddCommand>(make_unique<NumberCommand>(2), make_unique<NumberCommand>(3));

    EXPECT_EQ(command->Execute(), 5);
}
