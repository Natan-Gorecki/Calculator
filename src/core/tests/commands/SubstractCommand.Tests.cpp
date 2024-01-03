#include "gtest/gtest.h"
#include "commands/NumberCommand.h"
#include "commands/SubstractCommand.h"

using namespace std;

TEST(SubstractCommandTests, ShouldSubstractCommands)
{
    auto command = make_unique<SubstractCommand>(make_unique<NumberCommand>(2), make_unique<NumberCommand>(3));

    EXPECT_EQ(command->Execute(), -1);
}
