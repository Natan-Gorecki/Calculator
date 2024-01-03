#pragma once
#include <memory>
#include "Command.h"


class MultiplyCommand : public Command
{
public:
    MultiplyCommand(std::unique_ptr<Command> left, std::unique_ptr<Command> right)
        : mLeft(move(left)), mRight(move(right))
    {
    }
    virtual ~MultiplyCommand() {}
    double Execute() override
    {
        return mLeft->Execute() * mRight->Execute();
    }

private:
    std::unique_ptr<Command> mLeft;
    std::unique_ptr<Command> mRight;
};
