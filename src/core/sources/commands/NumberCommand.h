#pragma once
#include "Command.h"

class NumberCommand : public Command
{
public:
    NumberCommand(double number)
        : mNumber(number)
    {
    }
    virtual ~NumberCommand() {}
    double Execute() override
    {
        return mNumber;
    }

private:
    double mNumber;
};
