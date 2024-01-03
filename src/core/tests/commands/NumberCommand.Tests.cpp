#include "gtest/gtest.h"
#include "commands/NumberCommand.h"

using namespace std;

TEST(NumberCommandTests, ShouldReturnNumber)
{
    auto command = make_unique<NumberCommand>(123.456);

    EXPECT_EQ(command->Execute(), 123.456);
}
