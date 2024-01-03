#pragma once
#include <memory>
#include "Command.h"


class AddCommand : public Command
{
public:
    AddCommand(std::unique_ptr<Command> left, std::unique_ptr<Command> right)
        : mLeft(move(left)), mRight(move(right))
    {
    }
    virtual ~AddCommand() {}
    double Execute() override
    {
        return mLeft->Execute() + mRight->Execute();
    }

private:
    std::unique_ptr<Command> mLeft;
    std::unique_ptr<Command> mRight;
};
