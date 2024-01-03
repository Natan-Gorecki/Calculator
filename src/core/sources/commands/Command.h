#pragma once

class Command
{
public:
    virtual double Execute() = 0;
    virtual ~Command() {};
};
