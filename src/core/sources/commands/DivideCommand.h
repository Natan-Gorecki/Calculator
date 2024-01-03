#pragma once
#include <memory>
#include "Command.h"
#include "CommandException.h"

class DivideCommand : public Command
{
public:
    DivideCommand(std::unique_ptr<Command> left, std::unique_ptr<Command> right)
        : mLeft(move(left)), mRight(move(right))
    {
    }
    virtual ~DivideCommand() {}
    double Execute() override
    {
        double divisor = mRight->Execute();

        if (divisor == 0)
        {
            throw CommandException("Division by 0.");
        }

        return mLeft->Execute() / divisor;
    }

private:
    std::unique_ptr<Command> mLeft;
    std::unique_ptr<Command> mRight;
};
