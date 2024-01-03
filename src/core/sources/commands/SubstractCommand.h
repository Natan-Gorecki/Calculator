#pragma once
#include <memory>
#include "Command.h"


class SubstractCommand : public Command
{
public:
    SubstractCommand(std::unique_ptr<Command> left, std::unique_ptr<Command> right)
        : mLeft(move(left)), mRight(move(right))
    {
    }
    virtual ~SubstractCommand() {}
    double Execute() override
    {
        return mLeft->Execute() - mRight->Execute();
    }

private:
    std::unique_ptr<Command> mLeft;
    std::unique_ptr<Command> mRight;
};
