#pragma once
#include <stdexcept>

class CommandException : public std::exception
{
    using std::exception::exception;
};
