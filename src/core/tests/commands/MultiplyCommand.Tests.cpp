#include "gtest/gtest.h"
#include "commands/MultiplyCommand.h"
#include "commands/NumberCommand.h"

using namespace std;

TEST(MultiplyCommandTests, ShouldMultiplyCommands)
{
    auto command = make_unique<MultiplyCommand>(make_unique<NumberCommand>(2), make_unique<NumberCommand>(3));

    EXPECT_EQ(command->Execute(), 6);
}
